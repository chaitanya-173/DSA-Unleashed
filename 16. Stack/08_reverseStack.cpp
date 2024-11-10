#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void reverseStack(stack<int> &stack) {
  	
    vector<int> v;

    while (!stack.empty()) {
        int num = stack.top();
        v.push_back(num);
        stack.pop();
    }
    
    for(int i=0; i<v.size(); i++) {
        int num = v[i];
        stack.push(num);  
    } 

}

int main() {

    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    cout << stack.size() << endl;

    reverseStack(stack);

    cout << stack.size() << endl;
    
}