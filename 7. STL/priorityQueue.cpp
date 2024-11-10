#include <iostream>
#include <queue>
using namespace std;

int main(){
    //max heap
    priority_queue<int> maxi; //arranges elements in dec. order(1st element is max)

    //min heap
    priority_queue<int , vector<int>, greater<int> > mini; //arranges elements in inc. order(1st element in min)

    maxi.push(2);
    maxi.push(4);
    maxi.push(7);
    maxi.push(1);

    cout << "maxi Size -> " << maxi.size() <<endl;

    int n = maxi.size();
    for(int i=0; i<n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;

    mini.push(5);
    mini.push(2);
    mini.push(0);
    mini.push(4);

    cout << "mini Size -> " << mini.size() <<endl;

    int m = mini.size();
    for(int i=0; i<m; i++){
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;



}