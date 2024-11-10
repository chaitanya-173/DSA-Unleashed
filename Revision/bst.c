#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } 
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    } 
    else if (key < root->data) {
        return search(root->left, key);
    } 
    else {
        return search(root->right, key);
    }
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    // Traverse the tree to find the node to delete
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } 
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } 
    else {
        // Node to be deleted is found

        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: Node has only one child
        else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } 
        else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Node has two children
        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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
    root = insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 8);

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
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Node with value %d found.\n", key);
    } 
    else {
        printf("Node with value %d not found.\n", key);
    }

    // Delete a node from the tree
    int deleteKey = 20;
    root = deleteNode(root, deleteKey);
    printf("In-order traversal after deleting %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
