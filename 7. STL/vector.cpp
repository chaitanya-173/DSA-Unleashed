//vector is dynamic
#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int>v;

    cout << "capacity -> " << v.capacity() <<endl;

    v.push_back(1);
    cout << "capacity -> " << v.capacity() <<endl;

    v.push_back(2);
    cout << "capacity -> " << v.capacity() <<endl;

    v.push_back(3);
    cout << "capacity -> " << v.capacity() <<endl; //capacity-> total space for elements
    //full hote he capacity double ho jata hai
    cout << "size -> " << v.size() <<endl; //size-> n of elements

    cout << "Element at 2nd index -> " << v.at(2) <<endl;
    cout << "Empty or not -> " << v.empty() <<endl;
    cout << "First element -> " << v.front() <<endl;
    cout << "Last element -> " << v.back() <<endl;

    for(int i:v){
        cout << i << " ";
    }cout << endl; 

    v.pop_back();
    cout << "After pop back -> ";
    for(int i:v){
        cout << i << " ";
    }cout << endl; 

    v.clear();
    cout << "size -> " << v.size() <<endl; //clear se size 0 ho jata hai
    cout << "capacity -> " << v.capacity() <<endl; //capacity remains same
     
    vector<int>vec(5,1); //paanchon element ko 1 se initialize krdo

    for(int i:vec){
        cout << i << " ";
    }cout << endl; 

    vector<int> last(vec); //pehle vector ko dusre mein copy krna

    for(int i:last){
        cout << i << " ";
    }cout << endl; 


}
