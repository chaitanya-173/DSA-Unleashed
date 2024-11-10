#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int d) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = d;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int d) {
    if(root == NULL) {
        root = createNode(d);
    }
    else if(d < root -> data) {
        root -> left = insertNode(root -> left, d);
    }
    else {
        root -> right = insertNode(root -> right, d);
    }
    return root;
}

struct Node* searchNode(struct Node* root, int key) {
    if(root == NULL || root -> data == key) {
        return root;
    }
    else if(key < root -> data) {
        return searchNode(root -> left, key);
    }
    else {
        return searchNode(root -> right, key);
    }
}

struct Node* findMin(struct Node* root) {
    while(root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int val) {
    if(root == NULL) {
        return root;
    }

    //finding the node 
    if(val < root -> data) {
        root -> left = deleteNode(root -> left, val);
    }
    else if(val > root -> data) {
        root -> right = deleteNode(root -> right, val);
    }
    else {  //node found

        //0 child
        if(root -> left == NULL && root -> right == NULL) {
            free(root);
            root = NULL;    // ***
        }

        //1 child   ***
        else if(root -> left != NULL && root -> right == NULL) {
            struct Node* temp = root;
            root = root -> left;
            free(temp);
        }
        else if(root -> left == NULL && root -> right != NULL) {
            struct Node* temp = root;
            root = root -> right;
            free(temp);
        }

        //2 child
        else {
            struct Node* temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);  // ***
        }

    }
}

void inorderTraversal(struct Node* root) {  //LNR
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {  //NLR
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {  //LRN
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {

    struct Node* root = NULL;
    
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    int key = 40;
    struct Node* result = searchNode(root, key);
    if (result != NULL) {
        printf("Node with value %d found.\n", key);
    } 
    else {
        printf("Node with value %d not found.\n", key);
    }

    int deleteKey = 50;
    root = deleteNode(root, deleteKey);
    printf("In-order traversal after deleting %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");


}

