//to study - padding, greedy alignment (sizeof(ramesh) = 8 rather than 5)
//const keyword (object creation & functions), initalisation list
#include <iostream>
// #include "hero2.cpp"
using namespace std;

class Hero {  //user-defined datatype

    //properties
    private:  //access modifiers
    int health;
    public:
    char level;

    int getHealth() {  //getter - to get(fetch) private members
        return health;
    }

    void setHealth(int h) {  //setter - to set private members
        health = h;
    }

};

int main() {

    //creation of object (static allocation)
    // Hero2 h2;
    Hero ramesh;

    //using setter
    ramesh.setHealth(70);
    //using getter
    ramesh.level = 'A';

    cout << "Size: " << sizeof(ramesh) << endl;
    //empty class hoti toh size: 1 hota 

    cout << "Health is: " << ramesh.getHealth() << endl;
    cout << "Level is: " << ramesh.level << endl;

}