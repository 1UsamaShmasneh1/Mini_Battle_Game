//Usama Shmasneh,  308127125
//Shehab Shehab,   208263376
#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Player;

class Monster
{
private:
    std::string name;
    int currentHealth;
    int maxHealth;
    int attackPower;

public:
    Monster();
    Monster(const std::string& name, int maxHealth, int attackPower);
    ~Monster();

    void attack(Player& player) const;
    void receiveDamage(int damage);

    bool isAlive() const;
    const std::string& getName() const;
    int getCurrentHealth() const;
    int getMaxHealth() const;
    int getAttackPower() const;

    std::string getStatus() const;
};

#endif
