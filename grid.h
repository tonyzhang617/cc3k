#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
#include "NPCs/enemy_character.h"
#include "character.h"
#include "PCs/player_character.h"
#include "enum.h"

class Grid {
  std::vector<EnemyCharacter*> enemies;
  // TODO: add the item vector!!
  PlayerCharacter *player;
  std::vector<std::string> floor;
  std::string caption;
public:
  Grid(std::string floorFile);
  CellType getCellTypeAt(const int x, const int y) const;
  void print();
  void playerAttack(Direction dir);
  void playerConsumePotion(Direction dir);
  void playerMove(Direction dir);

  void enemyAttack(Character *enemy);

  void addAction(std::string action);
  // void playerConsumeGold();
  void findDestination(int &destx, int &desty, Direction dir) const;
  void removeEnemy(EnemyCharacter *enemy);
};

#endif
