#include <iostream>
using namespace std;

class Character
{
protected:
    int ID;
    string name;
    int level;
    float health;
    string weaponType;

public:
    Character(int ID, string name, int level, float health, string weaponType = "-") : ID(ID), name(name), level(level), health(health), weaponType(weaponType) {}

    virtual void attack()
    {
        cout << name << " Attacks!!!" << endl;
    }

    virtual void defend()
    {
        cout << name << " Defends!!!!" << endl;
    }

    virtual void displayStats()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << health << endl;
        if (!weaponType.empty())
        {
            cout << "Weapon Type: " << weaponType << endl;
        }
    }
};

class Warrior : public Character
{
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int ID, string name, int level, float health, int armorStrength, int meleeDamage, string weaponType = "-") : Character(ID, name, level, health, weaponType), armorStrength(armorStrength), meleeDamage(meleeDamage) {}

    void attack() override
    {
        cout << name << " attacks and dealing " << meleeDamage << " melee damage!" << endl;
    }
};

class Mage : public Character
{
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int ID, string name, int level, float health, int manaPoints, int spellPower, string weaponType = "") : Character(ID, name, level, health, weaponType), manaPoints(manaPoints), spellPower(spellPower) {}

    void defend() override
    {
        cout << name << " casts a magical barrier, reducing incoming damage!" << endl;
    }
};

class Archer : public Character
{
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int ID, string name, int level, float health, int arrowCount, int rangedAccuracy, string weaponType = "") : Character(ID, name, level, health, weaponType), arrowCount(arrowCount), rangedAccuracy(rangedAccuracy) {}

    void attack() override
    {
        cout << name << " fires an arrow with " << rangedAccuracy << "\% accuracy!" << endl;
    }
};

class Rogue : public Character
{
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int ID, string name, int level, float health, int stealthLevel, int agility, string weaponType = "") : Character(ID, name, level, health, weaponType), stealthLevel(stealthLevel), agility(agility) {}

    void displayStats() override
    {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main()
{
    Character *ptr;

    Warrior warrior1(834, "Igris", 78, 1000, 5000, 100, "Sword");
    Mage mage1(835, "Tusk", 69, 400, 1200, 60, "Fire magic");
    Archer archer1(836, "Robinhood", 36, 150, 50, 90, "Bow");
    Rogue rogue1(837, "Beru", 81, 1200, 89, 98, "Gatlings");

    ptr = &warrior1;
    ptr->attack();

    ptr = &mage1;
    ptr->defend();

    ptr = &archer1;
    ptr->attack();

    ptr = &rogue1;
    ptr->displayStats();

    return 0;
}
