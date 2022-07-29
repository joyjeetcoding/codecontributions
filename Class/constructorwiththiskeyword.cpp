#include <iostream>
using namespace std;

class hero
{
private:
    int health;

public:
    char level;

    hero
    {
        cout << "Default Constructor called " << endl;
    }
    // Parametarised Constructor
    hero(int health)
    {
        cout << "this -> " << this << endl;
        this->health = health;
    }

    hero(int health, char level)
    {
        this -> level = level;
        cout << "this -> " << this << endl;
        this->health = health;
    }

    // Getters
    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    // Setters
    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
};

int main()
{
    // creation of object
    // static memory allocation
    hero ramesh(10);
    cout << "Address of ramesh " << &ramesh << endl;
    ramesh.getHealth();
    // dynamically memory allocation
    hero *h = new hero(10);


    hero temp(22, 'A');
    return 0;
}