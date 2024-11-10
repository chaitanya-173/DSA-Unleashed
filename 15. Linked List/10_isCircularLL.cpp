#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = next;
    }

};

void insertNode(Node* &head, int element, int data) {

    //empty list
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        newNode -> next = newNode;
    }
    else {  //non-empty list
        Node* curr = head;
        while(curr -> data != element) {
            curr = curr -> next;
        }

        //element found => curr is representing element wala node
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}

void print(Node* head) {

    Node* temp = head;
    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while(temp != head);
    cout << endl;

}

bool isCircular(Node* &head) {

    if(head == NULL) {  //empty list
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }

    if(temp == head) {
        return true;
    }

    return false;

}

int main() {

    Node* head = NULL;
    insertNode(head, 10, 2);
    insertNode(head, 2, 4);
    insertNode(head, 4, 6);
    insertNode(head, 6, 8);
    insertNode(head, 8, 10);
    print(head);

    if(isCircular(head)) {
        cout << "Linked list is circular" << endl;
    }
    else {
        cout << "Linked list is not circular" << endl;
    }
    

}