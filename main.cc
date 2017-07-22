#include <iostream>
#include <string>
#include "grid.h"
#include "enum.h"

using namespace std;

int main() {
  Grid g("defaultLevel.txt");
  string cmd;

  cout << "Which player would you like to be? Please choose one:\ndrow, goblin, troll, vampire\n" <<
      "(The default character is a shade.)" << endl;
  cin >> cmd;

  g.initializePlayerCharacter(cmd);
  g.initializeFloor();
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
    }
    g.print();
  }

  return 0;
}
