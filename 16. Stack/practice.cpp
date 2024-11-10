#include <iostream>
using namespace std;

class stack {
    public:
        int *arr;
        int top;
        int size;
    
    //constructor
    stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(size - top > 1) {  
            top++;
            arr[top] = element;
        }
        else {
            cout << "stack overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout << "stack underflow" << endl;
        }
    }

    int peek() {
        if(top >= 0 && top < size) {
            return arr[top];
        }
        else {
            cout << "empty stack" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    stack s(5);

    cout << "empty or not: " << s.isEmpty() << endl;

    s.pop(); //stack underflow

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(7); //stack overflow

    cout << "top element: " << s.peek() << endl;

    cout << "empty or not: " << s.isEmpty() << endl;

}