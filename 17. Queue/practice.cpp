#include <iostream>
using namespace std;

class Queue {

    //properties
    public:
    int *arr;
    int size;
    int frnt;
    int rear;

    //constructor
    Queue(int size) {
        this -> size = size;
        arr = new int[size];
        frnt = 0;
        rear = 0;
    }

    public:
    //functions

    void enqueue(int element) {
        if(rear == size) {   //queue is full
            cout << "Queue is full" << endl;
        }  
        else {    //normal case
            arr[rear] = element;
            rear++;
        }
    }

    int dequeue() {
        if(frnt == rear) {   //queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        } 
        else {    //normal case
            int ans = arr[frnt];
            arr[frnt] = -1;
            frnt++;
            if(frnt == rear) {   //(queue is empty) front & rear = size, get back to 0th index
                frnt = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(frnt == rear) {  //queue is empty
            return -1;
        }
        else {
            int ans = arr[frnt];
            return ans;
            frnt++;
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

    Queue q(5);

    cout << q.isEmpty() << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << "front: " << q.front() << endl;

    cout << q.dequeue() << endl;

    cout << "front: " << q.front() << endl;
    /*
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    */

}