#include <fstream>
#include <iostream>
#include <string>
#include "grid.h"
#include "NPCs/human.h"
#include "NPCs/dwarf.h"
#include "PCs/shade.h"
#include "subject.h"
#include "observer.h"
using namespace std;

Grid::Grid(string floorFile): floor{vector<string>(25)} {
  // read in floor file
  ifstream ifs{floorFile};
  string line;

  if (ifs.good()) {
    char c;
    for (int i = 0; i < 25 && getline(ifs, line); ++i) {
      floor[i] = string(line);
    }
  }

  // initializing all fields
  player = new Shade(5, 5, this);
  enemies.push_back(new Human(5, 6, this));
  enemies.push_back(new Dwarf(6, 5, this));

  for (auto e : enemies) {
    player->attach(e);
  }
}

CellType Grid::getCellTypeAt(const int x, const int y) const {
  // TODO
  return CellType::FLOOR;
}

void Grid::print() {
  char flr[25][79];
  for (int i = 0; i < floor.size(); ++i) {
    fill(flr[i], flr[i] + 79, ' ');
    for (int j = 0; j < floor[i].size(); ++j) {
      flr[i][j] = floor[i][j];
    }
  }
  auto pos = player->getPosition();
  flr[pos.second][pos.first] = player->getChar();
  for (int i = 0; i < enemies.size(); ++i) {
    if (!enemies[i]->isDead()) {
      pos = enemies[i]->getPosition();
      flr[pos.second][pos.first] = enemies[i]->getChar();
    }
  }
  // TODO: add in items and stair

  for (int i = 0; i < 25; ++i) {
    for (int j = 0; j < 79; ++j) {
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
          addAction("Enemy has HP " + to_string(enemies[i]->getHp()) + ". ");
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
  // TODO: check if the player stepped on gold
}

/*
void playerConsumeGold(int x, int y) {
  pair<int, int> pos = player->getPosition();
  findDestination(pos.first, pos.second, dir);
}
*/

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