#include <iostream>
#include <list>
using namespace std;

int main(){

    list<int> l;

    l.push_back(3);
    l.push_front(2);
    l.push_front(1);

    for(int i: l){
        cout << i << " ";
    }cout << endl;

    // l.at(1); not possible (har element ke through travel krna pdta hai)

    l.erase(l.begin());

    for(int i: l){
        cout << i << " ";
    }cout << endl;

    cout << "Size -> " << l.size() <<endl;

    list<int> n(l); //copy the same list 
    for(int i: n){
        cout << i << " ";
    }cout << endl;

    list<int> m(5,100); //list of 5 elements all initialized by 100
    for(int i: m){
        cout << i << " ";
    }cout << endl;
}