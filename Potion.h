//Usama Shmasneh,  308127125
//Shehab Shehab,   208263376
#ifndef POTION_H
#define POTION_H

#include <string>

class Player;

class Potion
{
private:
    std::string name;
    int healingAmount;
    bool used;

public:
    Potion();
    Potion(const std::string& name, int healingAmount);
    ~Potion();

    void use(Player& player);
    bool isUsed() const;

    const std::string& getName() const;
    int getHealingAmount() const;

    std::string getStatus() const;
};

#endif
