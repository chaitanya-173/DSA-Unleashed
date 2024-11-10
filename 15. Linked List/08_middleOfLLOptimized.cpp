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

Node* getMiddle(Node* head) {

    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL) {

        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

    }
    
    return slow;

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