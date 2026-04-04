#include<iostream>
#include<queue>
#include<vector>

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

static int idx = -1;

Node* buildTree(vector<int> preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

int printPreorder(Node* root) {
    if (root == NULL) {
        return 0;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
    return 0;
}

// Convert tree into Sum Tree (update nodes)
int sumTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data += leftSum + rightSum;  // update node with subtree sum
    return root->data; // return updated sum to parent
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    cout << "Before SumTree: ";
    printPreorder(root);
    cout << endl;

    sumTree(root); // convert the tree

    cout << "After SumTree: ";
    printPreorder(root); // print updated values
    cout << endl;

    return 0;
}
