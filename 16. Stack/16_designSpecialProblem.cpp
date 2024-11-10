#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class SpecialStack {
    stack<int> s;
    int mini = INT_MAX;
    public:
        
    void push(int data) {
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if(data < mini) {
                int val = 2*data-mini;
                s.push(val);
                mini = data;
            }
            else {  //data > mini
                s.push(data);
            }
        }
    }

    void pop() {
        if(s.empty())
            return;
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return;
        }
        else {  //curr < mini
            int val = 2*mini-curr;
            mini = val;
        } 
    }

    int top() {
        if(s.empty()) {
            return -1;
        }
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    int getMin() {
        if(s.empty()) {
            return -1;
        }
        return mini;
    }  

};

int main() {

    
}