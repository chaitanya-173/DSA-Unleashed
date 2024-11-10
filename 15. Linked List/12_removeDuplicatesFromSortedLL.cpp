#include <iostream>
using namespace std;

class Node {

    public:
    int data;   //property
    Node* next;

    //paramterised constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destrcutor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory free for node with data: " << value << endl;
    }

};

void insertAtHead(Node* &head, int data) {

    Node* temp = new Node(data);  //new node(temp) creation
    temp -> next = head;  //1st node pe point krwaenge
    head = temp;  //head ko update krke temp pe point kra denge

}

void deleteNode(int position, Node* &head) {

    //deleting first node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free of first node
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

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }

}

void print(Node* &head) {

    Node* temp = head;  //new pointer bnaynge(temp)
    while(temp != NULL) {
        cout << temp -> data << " ";  //data print krayenge node ka
        temp = temp -> next;  //nod eko aage bdha denge
    }
    cout << endl;
}

Node* uniqueSortedList(Node* &head) {
    //empty list
    if(head == NULL) {
        return NULL;
    }

    //non-empty list
    Node* curr = head;

    while(curr != NULL) {

        if((curr -> next != NULL) && (curr -> data == curr -> next -> data)) {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else {  //not equal
            curr = curr -> next;
        }
    }

    return head;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    uniqueSortedList(head);
    print(head);
    

}

