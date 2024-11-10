#include <iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    //contructor (initialize TwoStack)
    TwoStack(int s) {
        this -> size = s;
        int top1 = -1;
        int top2 = s;
        arr = new int[s];
    }

    //push in stack-1
    void push1(int num) {
        //atleast ek empty space present hai
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    //push in stack-2
    void push2(int num) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    //pop from stack-1 and return popped element
    int pop1() {
        //check krenge ki element present hai ki nhi
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }     
    }

    //pop from stack-2 and return popped element
    int pop2() {
        //check krenge ki element present hai ki nhi
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }     
    }

};


int main() {

    TwoStack st(5);
    
    st.pop1();
    st.push1(20);
    st.pop1();

}