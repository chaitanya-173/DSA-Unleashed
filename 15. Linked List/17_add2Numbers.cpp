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

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}
        
Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forw = NULL;
            
    while(curr != NULL) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

Node* add(Node* first, Node* second) {

    Node* ansHead = NULL;
    int carry = 0;

    while(first != NULL || second != NULL || carry != NULL) {
        
        int val1 = 0;
        if(first != NULL)
            val1 = first -> data;

        int val2 = 0;
        if(second != NULL) 
            val2 = second -> data;

        int sum = carry + val1 + val2;  
        int digit = sum % 10;
        carry = sum /10;

        Node* temp = new Node(digit);
        //insert at head
        temp -> next = ansHead;
        ansHead = temp;
        
        if(first != NULL)
            first = first -> next;
        
        if(second != NULL)
            second = second -> next;

    }
    return ansHead;
}


int main() {

    Node* first = NULL;
    Node* second = NULL;

    insertAtHead(first, 5);
    insertAtHead(first, 4);
    insertAtHead(second, 5);
    insertAtHead(second, 4);
    insertAtHead(second, 3);
    print(first);
    print(second);

    //step-1: reverse input LL
    first = reverse(first);
    second = reverse(second);

    //step-2: add 2 LL
    Node* ans = add(first, second);

    print(ans);

}