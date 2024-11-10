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

void insertAtHead(Node* &head, int data) {

    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

}

void print(Node* head) {

    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;

}

Node* kreverse(Node* &head, int k) {

    //base case
    if(head == NULL) {
        return NULL;
    }

    //step1: reverse first k nodes
    Node* forw = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
        count++;
    }

    //step2: recursion dkh lega aage ka
    if(forw != NULL) {
        head -> next = kreverse(forw, k);
    }

    //step3: return head of reversed list
    return prev;

}

int main() {

    Node* head = NULL;
    
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    print(head);
    Node* newHead = kreverse(head, 2);
    print(newHead);

}