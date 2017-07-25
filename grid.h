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
#include <memory>

class Potion;
class Gold;
class Grid {
  std::vector<std::shared_ptr<EnemyCharacter>> enemies;
  std::vector<std::shared_ptr<Potion>> potions;
  std::vector<std::shared_ptr<Gold>> golds;
  std::shared_ptr<PlayerCharacter> player = nullptr;
  std::vector<std::string> floor;
  std::string caption;
  std::pair<int, int> stair;
  int level = 0;
  bool hasWon = false;

  void freeFloor();
public:
  const int WIDTH, HEIGHT;
  Grid();
  void setGrid(std::string floorFile, bool isDefault = true);
  CellType getCellTypeAt(const int x, const int y) const;
  void print();
  void playerAttack(Direction dir);
  void playerConsumePotion(Direction dir);
  void playerMove(Direction dir);

  void enemyAttack(Character *enemy);

  void addAction(std::string action);
  void findDestination(int &destx, int &desty, Direction dir) const;
  void setPlayerCharacter(std::shared_ptr<PlayerCharacter> pc);
  void addNewEnemy(std::shared_ptr<EnemyCharacter> ec);
  void addNewPotion(std::shared_ptr<Potion> p);
  void addNewGold(std::shared_ptr<Gold> g);
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
