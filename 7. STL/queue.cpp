//first in first out
#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue <string> q;

    q.push("Chaitanya");
    q.push("Chaudhary");

    cout << "First element -> " << q.front() <<endl;
    cout << "Size before pop-> " << q.size() <<endl;

    q.pop();

    cout << "First element -> " << q.front() <<endl;
    cout << "Size after pop-> " << q.size() <<endl;



}