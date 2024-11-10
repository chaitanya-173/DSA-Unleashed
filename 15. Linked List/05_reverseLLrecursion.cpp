#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}

void insertAtHead(Node* &head, int data) {

    if(head == NULL) {
        Node* firstNode = new Node(data);
        head = firstNode;
        return;
    }
    else {
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
    
}

void reverse(Node* &head, Node* curr, Node* prev) {

    //base case
    if(curr == NULL) {
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;

}

Node* reverseLL(Node* &head) {

    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;

}

int main() {

    Node* head = NULL;

    print(head);
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    print(head);
    reverseLL(head);
    print(head);

}