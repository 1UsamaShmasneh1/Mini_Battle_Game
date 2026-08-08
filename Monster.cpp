//Usama Shmasneh,  308127125
//Shehab Shehab,   208263376
#include "Monster.h"
#include "Player.h"

#include <iostream>

Monster::Monster()
    : name("Goblin"),
      currentHealth(80),
      maxHealth(80),
      attackPower(15)
{
}

Monster::Monster(const std::string& name, int maxHealth, int attackPower)
    : name(name.empty() ? "Goblin" : name),
      currentHealth(maxHealth > 0 ? maxHealth : 80),
      maxHealth(maxHealth > 0 ? maxHealth : 80),
      attackPower(attackPower > 0 ? attackPower : 20)
{
}

Monster::~Monster()
{
}

void Monster::attack(Player& player) const
{
    if (!isAlive())
        return;

    std::cout << name << " attacks " << player.getName()
              << " for " << attackPower << " damage.\n";

    player.receiveDamage(attackPower);
}

void Monster::receiveDamage(int damage)
{
    if (damage <= 0)
    {
        return;
    }

    currentHealth -= damage;

    if (currentHealth < 0)
    {
        currentHealth = 0;
    }

    std::cout << name << " receives " << damage << " damage.\n";
}

bool Monster::isAlive() const
{
    return currentHealth > 0;
}

const std::string& Monster::getName() const
{
    return name;
}

int Monster::getCurrentHealth() const
{
    return currentHealth;
}

int Monster::getMaxHealth() const
{
    return maxHealth;
}

int Monster::getAttackPower() const
{
    return attackPower;
}

std::string Monster::getStatus() const
{
    return std::string("Monster:\n")
           + "Name: " + name
           + "     "
           + "Health: " + std::to_string(currentHealth) + " / " + std::to_string(maxHealth) 
           + "     "
           + "Attack power: " + std::to_string(attackPower);
}
