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

Grid::Grid(string floorFile): HEIGHT{25}, WIDTH{79} {
  ifstream ifs{floorFile};
  string line;

  if (ifs.good()) {
    for (int i = 0; i < HEIGHT && getline(ifs, line); ++i) {
      floor.push_back(line);
    }
  }

  for (int i = 0; i < floor.size(); ++i) {
    for (int j = 0; j < floor[i].size(); ++j) {
      cout << floor[i][j];
    }
    cout << endl;
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
  // TODO: deadpotion and deadgold vectors
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

  cout << caption << endl << endl;
  caption = "";
}

void Grid::playerAttack(Direction dir) {
  bool isSuccessful = false;
  pair<int, int> pos = player->getPosition();
  findDestination(pos.first, pos.second, dir);
  for (int i = 0; i < enemies.size(); ++i) {
    if (enemies[i]->getPosition() == pos) {
      isSuccessful = true;
      if (player->attack(enemies[i])) {
        addAction("You attacked a " + enemies[i]->getRace() + ". ");
        if (enemies[i]->isDead()) {
          addAction("You slayed a " + enemies[i]->getRace() + ". ");
          // Remove dead body
          deadEnemies.push_back(enemies[i]);
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
  player->notifyObservers();
  // TODO
}

void Grid::playerMove(Direction dir) {
  player->makeMove(dir);
  player->notifyObservers();
  for (auto g : golds) {
    if (g->getPosition() == player->getPosition()) {
      g->consumedBy(player);
      //TODO: display message
      addAction("");
    }
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
  enemy->attack(player);
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
  PCFactory makePC{this};
  makePC.createEntity(getEntityFromString(race));
}

void Grid::initializeFloor() {
  if (level != 1) {
    //TODO
    //delete old info
  }

  //TODO
  //reset player and spawn

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
}