#include <iostream>
using namespace std;

class hero
{
private:
    int health;

public:
    char level;

    // hero
    // {
    //     cout << "Default Constructor called " << endl;
    // }
    // Parametarised Constructor
    hero(int health)
    {
        cout << "this -> " << this << endl;
        this->health = health;
    }

    void print()
    {
        cout << "Health " << this->health << endl;
        cout << "Level " << this->level << endl;
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
    hero S(70, 'C');       //Values to the parametarised constructor
    S.print();

    //Copy Constructor
    hero R(S);
    R.print();
   /* R.health = suresh.level;
    R.level = suresh.level;
    */


    return 0;
}