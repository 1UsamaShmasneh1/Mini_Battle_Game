#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Monster.h"
#include "Potion.h"

class Game
{
private:
    Player player;
    Monster monster;
    Potion potions[10];
    bool gameOver;
	bool isQuitting;
    int currentTurn;

    void showMenu() const;
    void showStatus() const;
    bool processChoice(int choice);
    void printLine(char ch) const;
    void performMonsterTurn();
    void checkGameState();
	bool playRound();
	bool usePotion();
	void resetGame();

public:
    Game();
    Game(const Player& player, const Monster& monster, const Potion potion[]);
    ~Game();

    void run();
};

#endif
