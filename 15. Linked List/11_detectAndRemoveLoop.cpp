#include <iostream>
#include <map>
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

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

bool detectLoop(Node* head) {

    if(head == NULL){
        return false;
    }

    map <Node*, bool> visited;

    Node* temp = head;
    while(temp != head) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}

Node* floydDetectLoop(Node* &head) {  

    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {

        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }   

        slow = slow -> next;

        if(slow == fast) {
            cout << "Intersection is " << slow -> data << endl;
            return slow;   //return address of POI pointer
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;

}

void removeLoop(Node* &head) {

    if(head == NULL) 
        return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
    
    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    }
    temp -> next = NULL;

}

int main() {

    Node* head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    print(head);

    head -> next -> next -> next -> next = head -> next;

    if(detectLoop(head)) {
        cout << "Loop detected" << endl;
    }
    else {
        cout << "Loop not found" << endl;
    }

    cout << endl;

    if(floydDetectLoop(head)) {
        cout << "Loop detected" << endl;
    }
    else {
        cout << "Loop not detected" << endl;
    }

    cout << "Loop starts at " << getStartingNode(head) -> data << endl;

    cout << endl;

    removeLoop(head);
    print(head);
    if(floydDetectLoop(head)) {
        cout << "Loop detected" << endl;
    }
    else {
        cout << "Loop not detected" << endl;
    }


}