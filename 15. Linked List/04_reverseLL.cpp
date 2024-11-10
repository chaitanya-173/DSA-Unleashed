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

Node* reverseLL(Node* &head) {

    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        //aage badha denge curr aur prev ko
        prev = curr;
        curr = forward;
    }

    //curr toh NULL pe point krne lgega aur prev last head ko darshayega
    return prev;

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


/*

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        //aage badha denge curr aur prev ko
        prev = curr;
        curr = forward;
    }

    //curr toh NULL pe point krne lgega aur prev last head ko darshayega
    return prev;
    
}

*/