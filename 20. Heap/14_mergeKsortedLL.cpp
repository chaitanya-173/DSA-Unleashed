#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return (a -> data > b -> data);
        }
};

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    } cout << endl;
}

Node* mergekLL(vector<Node*> &arr) {

    priority_queue< Node*, vector<Node*>, compare > pq;
    int k = arr.size();

    if(k == 0)  
        return NULL;

    for(int i=0; i<k; i++) {
        if(arr[i] != NULL) {
            pq.push(arr[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(pq.size() > 0) {
        Node* top = pq.top();
        pq.pop();

        if(top -> next != NULL) {
            pq.push(top -> next);
        }

        if(head == NULL) {  //ans LL is empty
            head = top;
            tail = top;
        }
        else {   //insert at LL
            tail -> next = top;
            tail = top;
        }
    }

    return head;

}

int main() {

    Node* head1 = new Node(3);
    head1 -> next = new Node(5);
    head1 -> next -> next = new Node(7);

    Node* head2 = new Node(2);
    head2 -> next = new Node(4);
    head2 -> next -> next = new Node(6);

    Node* head3 = new Node(6);
    head3 -> next = new Node(7);
    head3 -> next -> next = new Node(8);

    printLL(head1);
    printLL(head2);
    printLL(head3);

    vector<Node*> arr{head1, head2, head3};

    Node* newHead = mergekLL(arr);

    printLL(newHead);

}