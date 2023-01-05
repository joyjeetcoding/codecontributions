#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{

    // Creation
    map<string, int> m;

    // Insertion ways

    // Way 1
    pair<string, int> p = make_pair("Joy", 1);
    m.insert(p);

    // Way 2
    pair<string, int> pair2("Jeet", 2);
    m.insert(pair2);

    // Way 3
    m["mera"] = 1;

    // What will happen ?
    m["mera"] = 2;


    // Searching ways 
    cout << m["mera"] << endl;
    cout << m.at("Joy") << endl;

    // cout << m.at("Unknown key") << endl;
    cout << m["Unknown key"] << endl;

    // Size
    cout << m.size() << endl;

    // To check presence
    cout << m.count("bro") << endl;

    // Erase
    // m.erase("Joy");
    cout << m.size() << endl;

    // Access all element
    // using for loop

    // for(auto i:m)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    
    // iterator
    map<string, int> :: iterator it = m.begin();

    while (it != m.end())
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    

    return 0;
}