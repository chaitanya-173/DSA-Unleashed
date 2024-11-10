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

Node* merge(Node* first, Node* second) {

    if(first == NULL) 
        return second;
    
    if(second == NULL)
        return first;
    
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(first != NULL && second != NULL) {

        if(first -> data < second -> data) {
            temp -> next = first;
            temp = first;
            first = first -> next;
        }
        else {
            temp -> next = second;
            temp = second;
            second = second -> next;
        }

    }

    if(first == NULL) {
        temp -> next = second;
    }
    else {
        temp -> next = first;
    }

    ans = ans -> next;
    return ans;
     
}

int main() {

    Node* first = NULL;
    Node* second = NULL;

    insertAtHead(first, 7);
    insertAtHead(first, 5);
    insertAtHead(first, 4);
    insertAtHead(first, 2);
    insertAtHead(second, 6);
    insertAtHead(second, 5);
    insertAtHead(second, 3);
    insertAtHead(second, 2);
    insertAtHead(second, 1);
    print(first);
    print(second);

    Node* ans = merge(first, second);
    print(ans);
    

}