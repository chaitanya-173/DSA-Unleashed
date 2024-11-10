#include "DSA\19. Binary Search Tree\0import.cpp"

void takeInput(TreeNode* &root) {
    int d;
    cin >> d;
    while(d != -1) {
        insertIntoBST(root, d);
        cin >> d;
    }
}

void convertIntoSortedDLL(TreeNode* root, TreeNode* head) {
    //base case
    if(root == NULL)
        return;
    
    convertIntoSortedDLL(root -> right, head);

    root -> right = head;
    if(head != NULL)
        head -> left = root;
    head = root;

    convertIntoSortedDLL(root -> left, head);
}

TreeNode* mergeLL(TreeNode* first, TreeNode* second) {

    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    TreeNode* ans = new TreeNode(-1);
    TreeNode* temp = ans;

    while(first != NULL && second != NULL) {
        
        if(first -> data < second -> data) {
            temp -> right = first;
            first -> left = temp;
            temp = first;
            first = first -> right;
        }
        else {
            temp -> right = second;
            second -> left = temp;
            temp = second;
            second = second -> right;
        }

    }
    if(first == NULL) {
        temp -> right = second;
        second -> left = temp;
    }
    else {
        temp -> right = first;
        first -> left = temp;
    }

    ans = ans -> right;
    return ans;

}

int countNodes(TreeNode* head) {
    int count = 0;
    TreeNode* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp -> right;
    }
    return count;
}

TreeNode* sortedLLToBST(TreeNode* head, int n) {
    //base case
    if(n <= 0 || head == NULL)
        return NULL;
    
    TreeNode* leftSubtree = sortedLLToBST(head, n/2);

    TreeNode* root = head;
    root -> left = leftSubtree;

    root -> right = sortedLLToBST(head, n-n/2-1);
    return root;
}


int main() {

    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;

    cout << endl << "Enter 1st BST: " << endl;  //5 3 7 2 4 6 8 -1
    takeInput(root1);
    cout << endl << "Enter 2nd BST: " << endl;  //50 30 70 20 40 60 80 -1
    takeInput(root2);

    cout << endl << "Printing 1st BST: " << endl;
    printByLevelOrder(root1);
    cout << endl << "Printing 2nd BST: " << endl;
    printByLevelOrder(root2);

    //step 1: convert BST to Sorted LL in-place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 -> left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2 -> left = NULL;

    //step 2: merge 2 sorted LL
    TreeNode* head = mergeLL(head1, head2);

    //step 3: convert sorted LL to BST
    TreeNode* newRoot = sortedLLToBST(head, countNodes(head));

    printByLevelOrder(newRoot);

}