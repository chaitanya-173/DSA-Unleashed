//to do - doubly LL reverse
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

Node* reverse(Node* &head) {

    //base case
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* chotaHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chotaHead;
    
}

int main() {

    Node* head = NULL;

    print(head);
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    print(head);
    reverse(head);
    print(head);

}

/*
Let's go through an example with a diagram to help illustrate the process.

Suppose we have the following singly-linked list:

1 -> 2 -> 3 -> 4 -> 5 -> NULL

To reverse this list, we can use the given code.

1. Initially, the `reverseList` function is called with the head of the list (`1`).
2. Inside the `reverse1` function, the base case is not met because the head is not `NULL` and it has a `next` pointer.
3. The `reverse1` function is recursively called with the next node (`2`) as the argument.
4. The process continues until the base case is met when we reach the last node (`5`) in the original list.
5. At this point, the recursion starts to unwind. Let's see the state of the list at each step:

Step 1:
chotaHead = 5 (the last node)
Original list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

Step 2:
chotaHead = 5
Current node (head) = 4
Reverse the link between 4 and 5:
4 <- 5
Set head->next = NULL to remove the link to the next node:
4 -> NULL
Return chotaHead (5)

Step 3:
chotaHead = 5
Current node (head) = 3
Reverse the link between 3 and 4:
3 <- 4
Set head->next = NULL:
3 -> NULL
Return chotaHead (5)

Step 4:
chotaHead = 5
Current node (head) = 2
Reverse the link between 2 and 3:
2 <- 3
Set head->next = NULL:
2 -> NULL
Return chotaHead (5)

Step 5:
chotaHead = 5
Current node (head) = 1
Reverse the link between 1 and 2:
1 <- 2
Set head->next = NULL:
1 -> NULL
Return chotaHead (5)

6. The `reverseList` function now returns the new head of the reversed list, which is `chotaHead` (5).
7. The reversed list is: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

*/