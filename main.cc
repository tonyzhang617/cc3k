#include <iostream>
#include <string>
#include "grid.h"
#include "enum.h"

using namespace std;

int main() {
  Grid g("defaultLevel.txt");
  string cmd;

  g.startNewGame();
  g.print();

  while (cin >> cmd) {
    if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
        cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") {
      Direction dir = getDirFromString(cmd);
      g.playerMove(dir);
    } else if (cmd == "u") {
      cin >> cmd;
      Direction dir = getDirFromString(cmd);
      g.playerConsumePotion(dir);
    } else if (cmd == "a") {
      cin >> cmd;
      Direction dir = getDirFromString(cmd);
      g.playerAttack(dir);
    } else if (cmd == "q") {
      break;
    } else if (cmd == "r") {
      g.startNewGame();
    } else if (cmd == "f") {
      g.toggleFreezeEnemies();
    }
    g.print();

    bool end = false;
    if (g.playerHasWon()) {
      cout << "You win! ";
      end = true;
    } else if (g.playerHasLost()) {
      cout << "You lost! ";
      end = true;
    }

    if (end) {
      cout <<  "Your total score is " << g.playerScore() << "." << endl;
      cout << "Press \'r\' to start a new game, \'q\' to quit." << endl;
    }
  }

  return 0;
}
