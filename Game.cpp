#include "Game.h"

#include <iostream>
#include <limits>

Game::Game()
    : player(),
      monster(),
      gameOver(false),
      currentTurn(1)
{
	for (int i = 0; i < 10; ++i)
	{
		potions[i] = Potion();
	}
}

Game::Game(const Player& player, const Monster& monster, const Potion potion[])
    : player(player),
      monster(monster),
      gameOver(false),
      currentTurn(1)
{
	for (int i = 0; i < 10; ++i)
	{
		potions[i] = potion[i];
	}
}

Game::~Game()
{
}

void Game::run()
{
    std::cout << "Welcome to Mini Battle Game!\n\n";
    
    showStatus();

    while (!gameOver)
    {
        std::cout << "===== Turn " << currentTurn << " =====\n\n";
        showMenu();

        int choice = 0;
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number from 1 to 4.\n\n";
            continue;
        }

        if (!processChoice(choice)) continue;
        checkGameState();


        if (!gameOver && monster.isAlive() && choice != 3)
        {
            performMonsterTurn();
            checkGameState();
            ++currentTurn;
            continue;
        }

        if (choice == 3)
            continue;


        currentTurn = 1;

    }


    printLine('*');

    std::cout << "  ***      *      *     *  *****" << std::endl;
    std::cout << " *        * *     **   **  *" << std::endl;
    std::cout << " *  **   *****    * * * *  ****" << std::endl;
    std::cout << " *   *  *     *   *  *  *  *" << std::endl;
    std::cout << "  ***  *       *  *     *  *****" << std::endl;

    std::cout << std::endl;

    std::cout << "  ***   *       *  *****  ****" << std::endl;
    std::cout << " *   *  *       *  *      *   *" << std::endl;
    std::cout << " *   *   *     *   ****   ****" << std::endl;
    std::cout << " *   *    *   *    *      *  *" << std::endl;
    std::cout << "  ***      ***     *****  *   *" << std::endl;

    printLine('*');

}



void Game::showMenu() const
{
    std::cout << "Choose action:\n"
              << "1. Attack     "
              << "2. Use potion     "
              << "3. Show status     "
              << "4. Exit game\n\n";
}

void Game::printLine(char ch) const
{
    for (int i = 1; i <= 70; i++)
        std::cout << ch;
    std::cout << "\n";
}

void Game::showStatus() const
{
    printLine('*');
	std::cout << "                    ===== Player Status =====\n\n";
    std::cout << player.getStatus() << "\n\n";
	printLine('-');
    std::cout << monster.getStatus() << "\n\n";
	printLine('-');
    std::cout << "Potions: \n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << potions[i].getStatus() << "\n";
	}
	printLine('*');
}

bool Game::processChoice(int choice)
{
    switch (choice)
    {
    case 1:
        player.attack(monster);
        return true;

    case 2:
		return usePotion();
    case 3:
        showStatus();
        return true;

    case 4:
        std::cout << "You exited the game.\n";
        return true;

    default:
        std::cout << "Invalid choice. Please choose a number from 1 to 4.\n";
        return false;
    }
}

bool Game::usePotion()
{
	for (int i = 0; i < 10; ++i)
	{
		if (!potions[i].isUsed())
		{
			potions[i].use(player);
			return true;
		}
	}
	
    std::cout << "All potions have been used.\n";
	return false;
}

void Game::performMonsterTurn()
{
    monster.attack(player);
}

void Game::checkGameState()
{
    if (!monster.isAlive())
    {
        player.addScore(100);
        gameOver = true;

        std::cout << "\nYou defeated " << monster.getName() << "!\n"
                  << "Final score: " << player.getScore() << '\n';
    }
    else if (!player.isAlive())
    {
        gameOver = true;
        std::cout << "\n" << player.getName()
                  << " was defeated. Game over.\n";
    }
}
