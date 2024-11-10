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

    //destructor
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

void insertAtTail(Node* &tail, int data) {

    Node* temp = new Node(data);  //new node(temp) creation
    tail -> next = temp;  //tail ke next ko new node pe point krwaenge
    tail = temp;  //tail ko update krke temp pe bhjdo

}

void insertAtPosition(Node* &tail, Node* &head, int position, int data) {

    //edge case (agar 1st position pe insert krna ho toh)
    if(position == 1) {
        insertAtHead(head, data);
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
        insertAtTail(tail, data);
        return;
    }

    //creating a node for new data
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

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

int main() {

    //create a new node
    Node* node1 = new Node(10);  
    cout << node1 -> data << endl;
    //cout << node1 -> next << endl;

    //head pointed to new node
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 15);
    print(head);
    insertAtTail(tail, 13);
    print(head);
    insertAtTail(tail, 16);
    print(head);
    insertAtPosition(tail, head, 6, 37);
    print(head);
    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;
    deleteNode(3, head);  //to do - tail ko handle kro
    print(head);

    // if (head == NULL) {
    //     return newnode;
    // }
    
    // SinglyLinkedListNode* current_node = head;
    
    // while (current_node->next != NULL) {
    //     current_node = current_node->next;
    // }
    
    // current_node->next = newnode;
    
    // return head;

}