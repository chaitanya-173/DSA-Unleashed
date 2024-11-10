#include <iostream>
#include <deque>
using namespace std;

int main(){

    deque<int> d;

    d.push_front(2);
    d.push_back(3);
    d.push_front(1);

    for(int i: d){
        cout << i << " ";
    }cout << endl;

    d.pop_front();
    d.pop_back();

    for(int i: d){
        cout << i << " ";
    }cout << endl;

    d.push_back(3);
    d.push_front(1);

    cout << "Element at index 1 -> " << d.at(1) <<endl;
    cout << "First element -> " << d.front() <<endl;
    cout << "Last element -> " << d.back() <<endl;
    cout << "Empty or not -> " << d.empty() <<endl;
    cout << "Size -> " << d.size() <<endl;
    cout << "Max-size ->" << d.max_size() <<endl;
    
    d.erase(d.begin(),d.begin()+1);

    for(int i: d){
        cout << i << " ";
    }cout << endl;

    cout << "Size -> " << d.size() <<endl;






}

