#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
#include <iomanip>
#include "NPCs/enemy_character.h"
#include "character.h"
#include "PCs/player_character.h"
#include "enum.h"
#include <utility>

class Potion;
class Gold;
class Grid {
  std::vector<EnemyCharacter*> enemies, deadEnemies;
  std::vector<Potion *> potions;
  std::vector<Gold *> golds;
  PlayerCharacter *player = nullptr;
  std::vector<std::string> floor;
  std::string caption;
  std::pair<int, int> stair;
  int level = 0;
  bool hasWon = false;

  void freeFloor();
public:
  const int WIDTH, HEIGHT;
  Grid(std::string floorFile, bool isDefault = true);
  CellType getCellTypeAt(const int x, const int y) const;
  void print();
  void playerAttack(Direction dir);
  void playerConsumePotion(Direction dir);
  void playerMove(Direction dir);

  void enemyAttack(Character *enemy);

  void addAction(std::string action);
  void findDestination(int &destx, int &desty, Direction dir) const;
  void setPlayerCharacter(PlayerCharacter *pc);
  void addNewEnemy(EnemyCharacter *ec);
  void addNewPotion(Potion *p);
  void addNewGold(Gold *g);
  void setStair(int x, int y);
  void initializePlayerCharacter();
  void initializeFloor();
  bool playerHasWon() const;
  bool playerHasLost() const;
  int playerScore() const;
  void startNewGame();
  void toggleFreezeEnemies();
};

#endif
