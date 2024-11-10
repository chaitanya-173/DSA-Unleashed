#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& s, int num) {

    //base case
    if(s.empty() || (num > s.top())) {
        s.push(num);
        return;
    } 

    int n = s.top();
    s.pop();

    //recursive call
    sortedInsert(s, num);

    s.push(n);  //backtrack
}

void sortStack(stack<int>& s) {

    //base case
    if(s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    sortStack(s);

    sortedInsert(s, num);  //backtrack
}


int main() {

    stack<int> stack;
    stack.push(6);
    stack.push(3);
    stack.push(8);
    stack.push(1);
    stack.push(7);
    stack.push(4);

    sortStack(stack);

    cout << stack.top() << " ";
    stack.pop();
    cout << stack.top() << " ";    
    stack.pop();
    cout << stack.top() << " ";
    stack.pop();
    cout << stack.top() << " ";
    stack.pop();
    cout << stack.top() << " ";
    stack.pop();
    cout << stack.top() << " ";


    
}