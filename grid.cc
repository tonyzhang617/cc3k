#include <fstream>
#include <iostream>
#include "grid.h"
#include "NPCs/human.h"
#include "NPCs/dwarf.h"
#include "PCs/shade.h"
#include "factory/pc_factory.h"
#include "factory/enemy_factory.h"
#include "factory/gold_factory.h"
#include "factory/potion_factory.h"
#include "factory/stair_factory.h"
#include "gold/gold.h"
#include "potion/potion.h"
using namespace std;

Grid::Grid(string floorFile, bool isDefault): HEIGHT{25}, WIDTH{79} {
  ifstream ifs{floorFile};
  string line;

  if (ifs.good()) {
    for (int i = 0; i < HEIGHT && getline(ifs, line); ++i) {
      if (!isDefault) {
        for (int j = 0; j < WIDTH; j++) {
          char c = line[j];
          if ((c >= '0' && c <= '9') || c == '\\') {
            if (c >= '0' && c <= '5') {
              PotionFactory pf{this};
              pf.createPotion(j, i, getPotionFromInt(c-'0'));
            } else if (c >= '6' && c <= '9') {
              GoldFactory gf{this};
              gf.createGold(j, i, getGoldFromInt(c-'0'));
            } else if (c == '\\') {
              StairFactory sf{this};
              sf.createStair(j, i);
            }
            line[j] = '.';
          }
        }
      }
      floor.push_back(line);
    }
  }

  if (isDefault) {
    startNewGame();
  } else {
    EnemyFactory makeEnemy{this};
    for (int i = 0; i < 20; i++) {
      makeEnemy.createEntity();
    }

    for (auto e : enemies) {
      player->attach(e);
    }

    initializePlayerCharacter();
  }
}

CellType Grid::getCellTypeAt(const int x, const int y) const {
  if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) return CellType::ABYSS;

  pair<int, int> cur = make_pair(x, y);

  if (player != nullptr) {
    if (player->getPosition() == cur)
      return CellType::PC;

    if (stair == cur) return CellType::STAIR;

    for (auto e : enemies) {
      if (!e->isDead()) {
        if (e->getPosition() == cur)
          return CellType::ENEMY;
      }
    }

    for (auto p : potions) {
      if (!p->isConsumed()) {
        if (p->getPosition() == cur)
          return CellType::POTION;
      }
    }

    for (auto g : golds) {
      if (!g->isConsumed()) {
        if (g->getPosition() == cur)
          return CellType::GOLD;
      }
    }
  }

  char cell = floor[y][x];
  if (cell == '|' || cell == '-') return CellType::WALL;
  if (cell == '+') return CellType::DOORWAY;
  if (cell == '#') return CellType::PASSAGE;
  if (cell == '.') return CellType::FLOOR;

  return CellType::ABYSS;
}

void Grid::print() {
  char flr[HEIGHT][WIDTH];
  for (int i = 0; i < HEIGHT; ++i) {
    fill(flr[i], flr[i] + WIDTH, ' ');
    for (int j = 0; j < WIDTH; ++j) {
      flr[i][j] = floor[i][j];
    }
  }
  auto pos = player->getPosition();
  flr[pos.second][pos.first] = player->getChar();

  pos = stair;
  flr[pos.second][pos.first] = '\\';

  for (int i = 0; i < enemies.size(); ++i) {
    if (!enemies[i]->isDead()) {
      pos = enemies[i]->getPosition();
      flr[pos.second][pos.first] = enemies[i]->getChar();
    }
  }

  for (auto p : potions) {
    if (!p->isConsumed()) {
      pos = p->getPosition();
      flr[pos.second][pos.first] = p->getChar();
    }
  }

  for (auto g : golds) {
    if (!g->isConsumed()) {
      pos = g->getPosition();
      flr[pos.second][pos.first] = g->getChar();
    }
  }

  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      cout << flr[i][j];
    }
    cout << endl;
  }

  cout <<  "Race: " << player->getRace() << " Gold: " << player->getGold();
  cout << internal << setw(55) << "Floor " << level << endl;
  cout << "HP: " << player->getHp() << "\nAtk: " << player->getAtk() << "\nDef: " << player->getDef() << endl;
  cout << caption << endl << endl;
  caption = "";

  if (player->isDead()) {
    freeFloor();
  }
}

void Grid::playerAttack(Direction dir) {
  bool isSuccessful = false;
  pair<int, int> pos = player->getPosition();
  findDestination(pos.first, pos.second, dir);
  for (int i = 0; i < enemies.size(); ++i) {
    if (enemies[i]->getPosition() == pos) {
      isSuccessful = true;
      if (player->attack(enemies[i])) {
        addAction("You attacked a(n) " + enemies[i]->getRace() + ". ");
        if (enemies[i]->isDead()) {
          addAction("You slayed a(n) " + enemies[i]->getRace() + ". ");

          // free the dead enemy
          delete enemies[i];
          enemies[i] = nullptr;
          enemies.erase(enemies.begin()+i);
        } else {
          addAction("The " + enemies[i]->getRace() + " has HP " + to_string(enemies[i]->getHp()) + " remaining. ");
        }
      } else {
        addAction("Your attack missed. ");
      }
      break;
    }
  }
  if (!isSuccessful) {
    addAction("Your attack was not aimed at an enemy. ");
  }
  player->notifyObservers();
}

void Grid::playerConsumePotion(Direction dir) {
  pair<int, int> pos = player->getPosition();
  findDestination(pos.first, pos.second, dir);
  bool hasConsumed = false;
  for (int i = 0; i < potions.size(); ++i) {
    if (potions[i]->getPosition() == pos) {
      player->consumePotion(potions[i]);
      addAction("You consumed " + potions[i]->getType() + ". ");
      hasConsumed = true;

      // free the consumed potion
      delete potions[i];
      potions[i] = nullptr;
      potions.erase(potions.begin()+i);

      break;
    }
  }

  if (!hasConsumed) {
    addAction("There is no potion in that direction. ");
  }
  player->notifyObservers();
}

void Grid::playerMove(Direction dir) {
  player->makeMove(dir);

  for (int i = 0; i < golds.size(); ++i) {
    if (golds[i]->getPosition() == player->getPosition()) {
      if (golds[i]->consumedBy(player)) {
        addAction("You picked up a gold. ");

        // free the picked up gold
        delete golds[i];
        golds[i] = nullptr;
        golds.erase(golds.begin()+i);
      } else {
        addAction("You cannot pick up this gold. ");
      }
    }
  }

  if (stair == player->getPosition()) {
    if (level < 5) {
      initializeFloor();
      addAction("You reached the next floor. ");
    } else {
      freeFloor();
      hasWon = true;
    }
  } else {
    player->notifyObservers();
  }
}

void Grid::addAction(string action) {
  caption += action;
}

void Grid::findDestination(int &destx, int &desty, Direction dir) const {
  switch (dir) {
    case Direction::NO:
    case Direction::NE:
    case Direction::NW:
      desty--;
      break;
    case Direction::SO:
    case Direction::SE:
    case Direction::SW:
      desty++;
      break;
  }
  switch (dir) {
    case Direction::EA:
    case Direction::SE:
    case Direction::NE:
      destx++;
      break;
    case Direction::WE:
    case Direction::SW:
    case Direction::NW:
      destx--;
      break;
  }
}

void Grid::enemyAttack(Character *enemy) {
  if (enemy->attack(player)) {
    addAction("You were attacked by a(n) " + enemy->getRace() + ". ");
  } else {
    addAction("The " + enemy->getRace() + " missed an attack. ");
  }
}

void Grid::setPlayerCharacter(PlayerCharacter *pc) {
  player = pc;
}

void Grid::addNewEnemy(EnemyCharacter *ec) {
  enemies.push_back(ec);
}

void Grid::addNewPotion(Potion *p) {
  potions.push_back(p);
}

void Grid::addNewGold(Gold *g) {
  golds.push_back(g);
}

void Grid::setStair(int x, int y) {
  stair = make_pair(x, y);
}

void Grid::initializePlayerCharacter(string race) {
  string cmd;
  cout << "Which player would you like to be? Please choose one:\n" <<
      "drow, goblin, troll, vampire\n" <<
      "(The default character is a shade.)" << endl;
  cin >> cmd;
  PCFactory makePC{this};
  makePC.createEntity(getEntityFromString(race));
  addAction("The player character has spawned.");
}

void Grid::initializeFloor() {
  if (level >= 1) {
    freeFloor();
  }

  player->resetAtkDef();
  int x, y;
  while (1) {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    CellType ct = getCellTypeAt(x, y);
    if (ct == CellType::FLOOR) break;
  }
  player->setPosition(x, y);

  StairFactory makeStair{this};
  makeStair.createEntity();

  PotionFactory makePotion{this};
  for (int i = 0; i < 10; i++) {
    makePotion.createEntity();
  }

  GoldFactory makeGold{this};
  for (int i = 0; i < 10; i++) {
    makeGold.createEntity();
  }

  EnemyFactory makeEnemy{this};
  for (int i = 0; i < 20; i++) {
    makeEnemy.createEntity();
  }

  for (auto e : enemies) {
    player->attach(e);
  }

  level++;
}

bool Grid::playerHasWon() const {
  return hasWon;
}

bool Grid::playerHasLost() const {
  return player->isDead();
}

int Grid::playerScore() const {
  return player->getScore();
}

void Grid::freeFloor() {
  for (auto &e : enemies) {
    delete e;
    e = nullptr;
  }
  enemies.clear();

  for (auto &p : potions) {
    delete p;
    p = nullptr;
  }
  potions.clear();

  for (auto &g : golds) {
    delete g;
    g = nullptr;
  }
  golds.clear();

  player->clearAll();
}

void Grid::startNewGame() {
  if (player != nullptr) {
    freeFloor();
    delete player;
    player = nullptr;
  }

  g.initializePlayerCharacter(cmd);
  g.initializeFloor();
}

void Grid::toggleFreezeEnemies() {
  player->toggleFreezeAll();
}
