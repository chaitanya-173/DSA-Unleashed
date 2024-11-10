#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " <<  q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    cout << "Size of queue: " << q.size() << endl;

    q.pop();

    cout << "Front element: " <<  q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    q.pop();
    q.pop();

    cout << "Size of queue: " << q.size() << endl;

    cout << "Is empty: " << q.empty() << endl;



    

}