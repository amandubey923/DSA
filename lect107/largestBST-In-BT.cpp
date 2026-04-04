#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Structure to store info about subtree
struct Info {
    int size;     // Size of subtree
    int minVal;   // Minimum value in subtree
    int maxVal;   // Maximum value in subtree
    int ans;      // Size of largest BST in subtree
    bool isBST;   // Is subtree a BST?
};

Info largestBSTUtil(Node* root) {
    // Base case: empty tree
    if (root == NULL) 
        return {0, INT_MAX, INT_MIN, 0, true};

    // Leaf node is a BST of size 1
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    // Recur for left and right subtrees
    Info leftInfo = largestBSTUtil(root->left);
    Info rightInfo = largestBSTUtil(root->right);

    Info curr;
    curr.size = 1 + leftInfo.size + rightInfo.size;

    // If left & right are BSTs and current node is valid BST root
    if (leftInfo.isBST && rightInfo.isBST &&
        leftInfo.maxVal < root->data && root->data < rightInfo.minVal) {

        curr.minVal = min(leftInfo.minVal, root->data);
        curr.maxVal = max(rightInfo.maxVal, root->data);

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    // Otherwise, this is not BST
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int largestBST(Node* root) {
    return largestBSTUtil(root).ans;
}

// Driver code
int main() {
    /*
            50
           /  \
         30    60
        / \    / \
      5   20  45  70
                  / \
                65   80
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    cout << "Size of the largest BST is: " << largestBST(root) << endl;

    return 0;
}
