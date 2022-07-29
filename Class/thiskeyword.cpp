#include <iostream>
using namespace std;

class hero
{
private:
    int health;

public:
    char level;

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

    void print()
    {
        cout << level << endl;
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
    // cout << "Address of ramesh " << &ramesh << endl;
    ramesh.print();
    // dynamically memory allocation
    hero *h = new hero(10);
    h -> print();

    hero temp(22, 'A');
    temp.print();
    return 0;
}