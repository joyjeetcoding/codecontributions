#include<iostream>
using namespace std;

class student
{
    private:
    int health;

    public:

    char level;
    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

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
    //creation of object
    student s;

    cout << " Health is "<< s.getHealth() <<endl;

    //use of setter
    s.setHealth(70);
    s.level = 'A';

    cout << "Level is "<< s.level <<endl;
    return 0;
}