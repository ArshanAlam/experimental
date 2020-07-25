/**
 * The singleton design pattern.
 */

#include <iostream>
using namespace std;

enum Game {GAME_A, GAME_B};

class CardGame {
  public:
    CardGame() {
      cout << "Card Game Created" << endl;  
    }
    ~CardGame() {
      cout << "Card Game Destroyed" << endl;  
    }
    static CardGame * makeGame(Game type);
    virtual void printGameName() = 0;
};

class GameA : public CardGame {
  public:
    GameA() {
      cout << "Game A Created" << endl;
    }
    ~GameA() {
      cout << "Game A Destroyed" << endl; 
    }
    void printGameName() {
      cout << "Game A" << endl;
    }
};

class GameB : public CardGame {
  public:
    GameB() {
      cout << "Game B Created" << endl;
    }
    ~GameB() {
      cout << "Game B Destroyed" << endl; 
    }
    void printGameName() {
      cout << "Game B" << endl;
    }
};


CardGame * CardGame::makeGame(Game type) {
  switch(type) {
    case GAME_A:
      return new GameA();
    case GAME_B:
      return new GameB();
    default:
      return NULL;
  }
}

int main() {
  GameA * A = (GameA *) CardGame::makeGame(GAME_A);
  GameB * B = (GameB *) CardGame::makeGame(GAME_B);
  A->printGameName();
  B->printGameName();
  delete A;
  delete B;
  return 0;
}
