//Usama Shmasneh,  308127125
//Shehab Shehab,   208263376
#include "Potion.h"
#include "Player.h"

#include <iostream>

Potion::Potion()
    : name("Healing Potion"),
      healingAmount(50),
      used(false)
{
}

Potion::Potion(const std::string& name, int healingAmount)
    : name(name.empty() ? "Healing Potion" : name),
      healingAmount(healingAmount > 0 ? healingAmount : 35),
      used(false)
{
}

Potion::~Potion()
{
}

void Potion::use(Player& player)
{
    if (used)
    {
        std::cout << name << " has already been used.\n";
        return;
    }

    if (!player.isAlive())
    {
        std::cout << "The potion cannot be used because the player is defeated.\n";
        return;
    }

    if (player.getCurrentHealth() == player.getMaxHealth())
    {
        std::cout << "The player's health is already full.\n";
        return;
    }

    std::cout << player.getName() << " uses " << name << ".\n";
    player.heal(healingAmount);
    used = true;
}

bool Potion::isUsed() const
{
    return used;
}

const std::string& Potion::getName() const
{
    return name;
}

int Potion::getHealingAmount() const
{
    return healingAmount;
}

std::string Potion::getStatus() const
{
    return "Name: " + name
           + "     "
           + "Healing amount: " + std::to_string(healingAmount)
		   + "     "
           + "Used: " + (used ? "Yes" : "No");
}
