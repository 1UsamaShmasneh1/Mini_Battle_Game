//Usama Shmasneh,  308127125
//Shehab Shehab,   208263376
#include "Player.h"
#include "Monster.h"

#include <iostream>

Player::Player()
    : name("Hero"),
      currentHealth(100),
      maxHealth(100),
      attackPower(20),
      score(0)
{
}

Player::Player(const std::string& name, int maxHealth, int attackPower)
    : name(name.empty() ? "Hero" : name),
      currentHealth(maxHealth > 0 ? maxHealth : 100),
      maxHealth(maxHealth > 0 ? maxHealth : 100),
      attackPower(attackPower > 0 ? attackPower : 15),
      score(0)
{
}

Player::Player(const std::string& name, int maxHealth, int attackPower, int score)
    : name(name.empty() ? "Hero" : name),
      currentHealth(maxHealth > 0 ? maxHealth : 100),
      maxHealth(maxHealth > 0 ? maxHealth : 100),
      attackPower(attackPower > 0 ? attackPower : 15),
      score(score)
{
}

Player::~Player()
{
}

void Player::attack(Monster& monster) const
{
    if (!isAlive())
    {
        std::cout << name << " cannot attack because the player is defeated.\n";
        return;
    }

    std::cout << name << " attacks " << monster.getName()
              << " for " << attackPower << " damage.\n";

    monster.receiveDamage(attackPower);
}

void Player::receiveDamage(int damage)
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

void Player::heal(int amount)
{
    if (amount <= 0 || !isAlive())
    {
        return;
    }

    const int oldHealth = currentHealth;
    currentHealth += amount;

    if (currentHealth > maxHealth)
    {
        currentHealth = maxHealth;
    }

    std::cout << name << " heals "
              << currentHealth - oldHealth
              << " health points.\n";
}

void Player::addScore(int amount)
{
    if (amount > 0)
    {
        score += amount;
    }
}

bool Player::isAlive() const
{
    return currentHealth > 0;
}

const std::string& Player::getName() const
{
    return name;
}

int Player::getCurrentHealth() const
{
    return currentHealth;
}

int Player::getMaxHealth() const
{
    return maxHealth;
}

int Player::getAttackPower() const
{
    return attackPower;
}

int Player::getScore() const
{
    return score;
}

std::string Player::getStatus() const
{
    return std::string("Player:\n")
           +"Name: " + name 
           + "     "
           + "Health: " + std::to_string(currentHealth) + " / " + std::to_string(maxHealth)
		   + "     "
           + "Attack power: " + std::to_string(attackPower)
		   + "     "
           + "Score: " + std::to_string(score);
}
