#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int element) {

    //base case
    if(s.empty()) {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    solve(s, element);

    //backtracking
    s.push(num);

}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << s.size() << endl;

    solve(s, 7);

    cout << s.size() << endl;
    
}