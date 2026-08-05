#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Monster;

class Player
{
private:
    std::string name;
    int currentHealth;
    int maxHealth;
    int attackPower;
    int score;

public:
    Player();
    Player(const std::string& name, int maxHealth, int attackPower);
    Player(const std::string& name, int maxHealth, int attackPower, int score);
    ~Player();

    void attack(Monster& monster) const;
    void receiveDamage(int damage);
    void heal(int amount);
    void addScore(int amount);
    bool isAlive() const;

    const std::string& getName() const;
    int getCurrentHealth() const;
    int getMaxHealth() const;
    int getAttackPower() const;
    int getScore() const;

    std::string getStatus() const;
};

#endif
