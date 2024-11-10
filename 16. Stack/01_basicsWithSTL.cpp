#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(5);

    s.pop();

    cout << "Top element: " << s.top() << endl;

    cout << "Is empty or not: " << s.empty() << endl;

    cout << "Size: " << s.size() << endl;

}