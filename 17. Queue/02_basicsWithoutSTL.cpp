#include <iostream>
using namespace std;

class Queue {

    //properties
    public:
    int *arr;
    int size;
    int qfront;
    int rear;

    //constructor
    Queue(int size) {
        this -> size = size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    public:

    //functions of queue

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is full" << endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) 
            return -1;
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear)
            return -1;
        else {
            return arr[qfront];
            qfront++;
        }
    }

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        return false;
    }

};

int main() {

    Queue q(5);

    cout << "Is empty: " << q.isEmpty() << endl;

    cout << q.dequeue() << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Is empty: " << q.isEmpty() << endl;

    cout << "Front: " << q.front() << endl;

    cout << q.dequeue() << endl;

    cout << "Front: " << q.front() << endl;







}