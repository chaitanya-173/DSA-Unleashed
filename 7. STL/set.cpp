//saare elements unique hone chahiye
//kisi bhi element ki modification nhi ho skti 
//sorted order mein set return hota hai
#include <iostream>
#include <set>
using namespace std;

int main(){

    set <int> s;

    s.insert(5);
    s.insert(3);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(6);
    s.insert(1);
    s.insert(9);

    for(int i: s){
        cout << i << " ";
    }cout << endl;

    set <int>::iterator it = s.begin();
    it++;
    s.erase(it);

    for(int i: s){
        cout << i << " ";
    }cout << endl;

    cout << "Count -> " << s.count(5) <<endl; //checks if the element is there or not
    cout << "Count -> " << s.count(2) <<endl;

    set <int> :: iterator itr = s.find(5);
    cout << "Value present at itr -> " << *it << endl;

    for(int i: s){
        cout << i << " ";
    }cout << endl;

    cout << s.count(2) << endl;
    cout << s.count(5) << endl;

    
    
}



