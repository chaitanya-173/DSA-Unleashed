//bruteforce
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

int getLength(Node* head) {

    int len = 0;
    while(head != NULL) {
        len++;
        head = head -> next;
    }

    return len;
}

Node* getMiddle(Node* head) {

    int len = getLength(head);
    int ans = len/2;

    Node* temp = head;
    while(ans) {
        temp = temp -> next;
        ans--;
    }
    
    return temp;

}

int main() {

    Node* head = NULL;

    print(head);
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    print(head);
    Node* answer = getMiddle(head);
    cout << answer -> data << endl;

}