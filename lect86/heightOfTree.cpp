#include<iostream>
#include<vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}
//height of tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

//count of nodes  method 1

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//count of nodes method 2
int countNodesMethod2(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftCount = countNodesMethod2(root->left);
    int rightCount = countNodesMethod2(root->right);
    return leftCount + rightCount + 1;
}
//sum of nodes 
int sumOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum + rightSum + root->data;
}


int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    cout << "Height of tree: " << height(root) << endl;
    cout << "Count of nodes (Method 1): " << countNodes(root) << endl;
    cout << "Count of nodes (Method 2): " << countNodesMethod2(root) << endl;
    cout << "Sum of nodes: " << sumOfNodes(root) << endl;
    return 0;
}
