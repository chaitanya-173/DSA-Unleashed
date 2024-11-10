#include <iostream>
#include <bits/stdc++.h> 
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

Node *uniqueUnsortedList(Node *head) {
  
    if (head == NULL)
        return NULL;

    unordered_map<int, bool> visited;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL) {

        if (visited[curr->data] == true) {

        curr = curr->next;

        delete (prev->next);
        prev->next = curr;

        continue;
        }

        visited[curr->data] = true;

        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 7);
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 7);
    insertAtHead(head, 2);
    print(head);

    uniqueUnsortedList(head);
    print(head);
    

}

