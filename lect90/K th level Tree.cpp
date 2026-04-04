#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* left ;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
//K th level of Binary Tree
void KthLevel(Node* root, int K){
    if(root == NULL){
        return ;
    }
    if(K == 1){
        cout<< root->data << " ";
        return ;
    }
    KthLevel(root->left, K-1);
    KthLevel(root->right, K-1);
}

int main()
{
   vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);
    KthLevel(root, 2); // Change the value of K to get different levels

    return 0;
}