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

Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
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

bool isPalindrome(Node *head) {
        
        if(head -> next == NULL) 
            return true;
        
        //step-1: find mid
        Node* middle = getMid(head);
        
        //ste-2: reverse list after middle
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3: compare both halves
        Node* head1 = head;
        Node* head2 = middle -> next;
        while(head2 != NULL) {
            if(head1 -> data != head2 -> data) {
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        //step4: repeat step-2 (optional)
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
        
    }
int main() {

    Node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    cout << isPalindrome(head) << endl;



}