#include <iostream>
using namespace std;

class student
{
private:
    int health;

public:
    char level;

    //Getters
    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }


    //Setters
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
    student s;
    s.setHealth(80);
    s.setLevel('A');
    cout << "Level is " << s.level << endl;
    cout << "Health is " << s.getHealth() << endl;

    // dynamically memory allocation
    student *t = new student;
    t->setHealth(70);
    t->setLevel('B');
    cout << "Level is " << (*t).level << endl;
    cout << "Health is " << (*t).getHealth() << endl;

    //OR

    cout << "Level is " << t->level << endl;
    cout << "Health is " << t->getHealth() << endl;

    return 0;
}