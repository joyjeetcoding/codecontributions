#include <iostream>
#include<string.h>
using namespace std;

class hero
{
private:
    int health;

public:
    char *name;     //dynamically allocated
    char level;
    static int timetocomplete;

    hero()
    {
        cout << "Simple Constructor called " << endl;
        name = new char[100];
    }
    // Parametarised Constructor
    hero(int health)
    {
        cout << "this -> " << this << endl;
        this->health = health;
    }

    void print()
    {
        cout << endl;
        cout << "[ Name: " << this->name << ", ";
        cout << "Health " << this->health << ", ";
        cout << "Level " << this->level << " ]";
        cout << endl;
    }

    // Parametarised Constructor
    hero(int health, char level)
    {
        this->level = level;
        cout << "this -> " << this << endl;
        this->health = health;
    }

    // copy constructor
    hero(hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name = ch;
        
        cout << "Copy constructor called " << endl;
        this->health = temp.health;
        this->level = temp.level;
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

    void setname(char name[])
    {
        strcpy(this->name, name);
    }

    //Destructor
    ~hero()
    {
        cout << "Destructor called" << endl;
    }
};

int hero::timetocomplete = 5;

int main()
{
    cout << hero::timetocomplete << endl;

    hero a;

    cout << a.timetocomplete << endl;
    return 0;
}