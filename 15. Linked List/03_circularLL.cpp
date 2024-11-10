#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    
    //destructor
    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }

};

void print(Node* tail) {

    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = tail;
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;

}

void insertNode(Node* &tail, int element, int data) {

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else {  //non-empty list
        Node* curr = tail;
        while(curr -> data != element) {
            curr = curr -> next;
        }

        //element found => curr is representing element wala node
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }
    else { //non-empty list
        //assuming that value is present int the list
        Node* prev = tail;
        Node* curr = prev -> next;
        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //for 1 node LL
        if(curr == prev) {
            tail = NULL;
        }
        //>=2 node LL
        else if(tail == curr) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }


}

int main() {

    Node* tail = NULL;
    
    //element list mein insertion
    insertNode(tail, 5, 13);
    print(tail);
    insertNode(tail, 13, 10);
    print(tail);
    insertNode(tail, 13, 15);
    print(tail);
    insertNode(tail, 15, 17);
    print(tail);
    insertNode(tail, 13, 19);
    print(tail);
    deleteNode(tail, 13);
    print(tail);
    deleteNode(tail, 17);
    print(tail);
    deleteNode(tail, 19);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
    deleteNode(tail, 15);
    print(tail);


}