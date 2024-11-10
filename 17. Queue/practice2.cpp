#include <iostream>
using namespace std;

class queue {
    public:
        int *arr;
        int size;
        int frnt;
        int rear;
    
    //constructor
    queue(int s) {
        this -> size = size;
        arr = new int[size];
        frnt = 0;
        rear = 0;
    }

    void enqueue(int element) {
        if(rear == size) {
            cout << "queue overflow" << endl;
        }
        else {
            arr[rear] = element;
            rear++;
        }
    }

    void dequeue() {
        if(frnt == rear) {
            cout << "queue underflow" << endl;
        }
        else {
            arr[frnt] = -1;
            frnt++;
            if(frnt == rear) {  //last element of queue popped - get back to start
                frnt = 0;
                rear = 0;
            }
        }
    }

    int front() {
        if(frnt == rear) {
            return -1;
        }
        else {
            return arr[frnt];
        }
    }

    bool isEmpty() {
        if(frnt == rear) {
            return true;
        }
        return false;
    }

};

int main() {

    queue q(5);

    cout << "is empty or not: " << q.isEmpty() << endl;
    
    q.dequeue();

    cout << q.front() << endl;

    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(7);  //queue overflow

    cout << "front element: " << q.front() << endl;

    q.dequeue();

    cout << "front element: " << q.front() << endl;

    cout << "is empty or not: " << q.isEmpty() << endl;




}