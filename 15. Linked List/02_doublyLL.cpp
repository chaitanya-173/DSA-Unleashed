#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data: " << val << endl;
    }

};

//traversing a LL
void print(Node* head) {

    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}

//gives length of LL
int getLength(Node* head) {

    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;

}

void insertAtHead(Node* &head, Node* &tail, int data) {

    //empty list
    if(head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}

void insertAtTail(Node* &tail, Node* &head, int data) {

    //empty list
    if(tail == NULL) {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data) {

    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    //traversing till (n-1)th position
    Node* temp = head;
    int count = 1;
    while(count < position-1) {
        temp = temp -> next;
        count++;
    }

    //edge case (agar last position pe insert krna ho toh - tail bhi update krna pdega)
    if(temp -> next == NULL) {
        insertAtTail(tail, head, data);
        return;
    }

    //creating node for data
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void deleteNode(int position, Node* &head) {

    //deleting first node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head= temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    //deleting any middle or last node
    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }

}

int main() {

    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL; 
    
    print(head);
    cout << "Length: " << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);
    insertAtHead(head, tail, 12);
    print(head);
    insertAtHead(head, tail, 13);
    print(head);

    insertAtTail(tail, head, 9);
    print(head);
    insertAtTail(tail, head, 8);
    print(head);
    insertAtTail(tail, head, 7);
    print(head);

    cout << "Length: " << getLength(head) << endl;

    insertAtPosition(tail, head, 4, 20);
    print(head);
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    deleteNode(1, head);
    print(head);
    deleteNode(6, head);
    print(head);
    deleteNode(3, head);  //to do - tail ko handle kro
    print(head);  

}