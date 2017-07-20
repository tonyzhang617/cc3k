#include <fstream>
#include <iostream>
#include <string>
#include "grid.h"
#include "NPCs/human.h"
#include "NPCs/dwarf.h"
#include "PCs/shade.h"
using namespace std;

Grid::Grid(string floorFile): floor{vector<vector<char>>(25)} {
  // read in floor hahaha...
  ifstream ifs{floorFile};
  string line;

  char c;
  for (int i = 0; i < 25; ++i) {
    for (int j = 0; j < 79 && ifs.get(c); ++j) {
      floor[i].push_back(c);
    }
  }

  // initializing all fields
  player = new Shade(5, 5, this);
  enemies.push_back(new Human(5, 6, this));
  enemies.push_back(new Dwarf(6, 5, this));
}

CellType Grid::getCellTypeAt(const int x, const int y) const {
  // TODO
  return CellType::FLOOR;
}

void Grid::print() {
  for (auto it = floor.begin(); it != floor.end(); ++it) {
    for (int i = 0; i < it->size(); ++i) {
      cout << it->at(i);
    }
    cout << endl;
  }
  cout << caption << endl << endl;
  caption = "";
}

void Grid::playerAttack(Direction dir) {
  pair<int, int> pos = player->getPosition();
  findDestination(pos.first, pos.second, dir);
  for (int i = 0; i < enemies.size(); ++i) {
    if (enemies[i]->getPosition() == pos) {
      player->attack(enemies[i]);
      break;
    }
  }
//  for (auto it = enemies.begin(); it != enemies.end(); ++it) {
//    if (it->getPosition() == pos) {
//      player->attack(it);
//      break;
//    }
//  }
}

void Grid::playerConsumePotion(Direction dir) {
  pair<int, int> pos = player->getPosition();
  findDestination(pos.first, pos.second, dir);
  // TODO
}

void Grid::playerMove(Direction dir) {
  player->makeMove(dir);
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
