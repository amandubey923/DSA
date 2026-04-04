#include<iostream>
#include<vector>
using namespace std;

// Node class to represent each node of the BST
class Node {
public:
    int data;       // value of the node
    Node* left;     // pointer to left child
    Node* right;    // pointer to right child

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a value into BST
Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val); // create a new node if tree is empty
    }
    if(val < root->data) {
        root->left = insert(root->left, val); // insert into left subtree
    }else{
        root->right = insert(root->right, val); // insert into right subtree
    }
    return root;
}

// Build BST from a given array (unsorted)
Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for(int v : arr){
        root = insert(root, v);  // insert each element into BST
    }
    return root;
}

// Build a height-balanced BST from a sorted array
Node* buildBSTFromSorted(vector<int> arr, int st, int end){
    if(st > end){
        return NULL; // base case
    }
    int mid = (st + end) / 2;
    Node* root = new Node(arr[mid]); // middle element becomes root
    root->left = buildBSTFromSorted(arr, st, mid-1);   // build left subtree
    root->right = buildBSTFromSorted(arr, mid+1, end); // build right subtree
    return root;
}

// Inorder traversal (LNR) to collect values in sorted order
void inorder(Node* root, vector<int>& arr) {
    if(root == NULL){
        return ;
    }
    inorder(root->left, arr);        // visit left subtree
    arr.push_back(root->data);       // store root value
    inorder(root->right, arr);       // visit right subtree
}

// Merge two BSTs into a single BST
Node* merge2BST(Node* root1, Node* root2){
    vector<int> arr1, arr2;
    
    // Get inorder traversal of both BSTs (gives sorted arrays)
    inorder(root1, arr1);
    inorder(root2, arr2);

    // Merge the two sorted arrays
    vector<int> temp;
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i++]);
        }else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i<arr1.size()){ temp.push_back(arr1[i++]); }
    while(j<arr2.size()){ temp.push_back(arr2[j++]); }

    // Build a balanced BST from merged sorted array
    return buildBSTFromSorted(temp, 0, temp.size()-1);
}

// Driver code
int main(){
    // Input arrays (unsorted)
    vector<int> arr1 = {8,2,1,10};
    vector<int> arr2 = {5,3,0};

    // Convert arrays into BSTs
    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    // Merge the two BSTs into one balanced BST
    Node* mergedRoot = merge2BST(root1, root2);

    // Print inorder traversal of the merged BST (sorted sequence)
    vector<int> seq;
    inorder(mergedRoot, seq);
    for(int v : seq){
        cout<<v<<" ";
    }
    cout<<endl;

    return 0;
}