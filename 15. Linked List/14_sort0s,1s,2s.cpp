#include <iostream>
using namespace std;

Node* sortList(Node *head){
    
    if(head==NULL ||head->next==NULL){
        return head;
    }

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp != NULL) {

        if(temp -> data == 0)
            zeroCount++;

        if(temp -> data == 1) 
            oneCount++;

        if(temp -> data == 2)
            twoCount++;

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL) {

        if(zeroCount) {
            temp -> data = 0;
            zeroCount--;
        }

        if(oneCount) {
            temp -> data = 1;
            oneCount--;
        }

        if(twoCount) {
            temp -> data = 2;
            twoCount--;
        }

        temp = temp -> next;
    }
    return head;
    
}

int main() {



}