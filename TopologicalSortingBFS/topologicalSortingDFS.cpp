#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;
class Graph{
    int V;
    list<int> *l; // int *arr
public:
    Graph(int V){
        this-> V= V;
        l = new list<int>[V];
        // arr = new int[V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);//only directed edges
       // l[v].push_back(u);
    }
    void dfs(int curr , vector<bool> &vis, stack<int> &s){
        vis[curr]= true;
        for(int v: l[curr]){
            if(!vis [v]){
                dfs(v, vis, s);
            }
        }
        s.push(curr);
    }
    void topologicalSorting(){
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, s);
            }
        }
        while(s.size()>0){
            cout<< s.top()<< "    ";
            s.pop();
        }
        cout<<endl;
    }
};
int main(){
    Graph g(6);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,3);
    g.topologicalSorting();
    return 0;   
}


// Topological Sorting using DFS
// ---------------------------------------------

// Definition:
// Topological Sorting is a linear ordering
// of vertices in a Directed Acyclic Graph (DAG)
// such that for every directed edge u -> v,
// vertex u appears before v in the ordering.

// Topological Sorting works only for:
// 1. Directed Graph
// 2. Acyclic Graph (No Cycle)


// Working of Algorithm
// ---------------------------------------------
// 1. Start DFS traversal from unvisited node.
// 2. Visit all adjacent nodes recursively.
// 3. After visiting all neighbors,
//    push current node into stack.
// 4. After DFS completion,
//    pop stack elements to get answer.


// Why Stack is Used
// ---------------------------------------------
// A node is pushed into stack only after
// all its dependent nodes are processed.

// Stack stores nodes in reverse finishing order.


// Data Structures Used
// ---------------------------------------------

// 1. Adjacency List
// list<int> *l;
// Used to store graph connections.


// 2. Visited Array
// vector<bool> vis;
// Tracks visited nodes.


// 3. Stack
// stack<int> s;
// Stores topological order.


// DFS Function Logic
// ---------------------------------------------
// Step 1:
// Mark current node as visited.

// Step 2:
// Traverse all adjacent neighbors.

// Step 3:
// If neighbor is not visited,
// call DFS recursively.

// Step 4:
// After visiting all neighbors,
// push current node into stack.


// Time Complexity
// ---------------------------------------------
// O(V + E)

// V = Number of Vertices
// E = Number of Edges


// Space Complexity
// ---------------------------------------------
// O(V)

// Used for:
// 1. Visited Array
// 2. Recursion Stack
// 3. Stack


// Example Graph
// ---------------------------------------------
// 3 -> 1
// 2 -> 3
// 4 -> 0
// 4 -> 1
// 5 -> 0
// 5 -> 3


// Possible Topological Order
// ---------------------------------------------
// 5 4 2 3 1 0

// Multiple correct answers are possible.


// Pseudo Code
// ---------------------------------------------

// TopologicalSort(Graph)

// create visited array initialized with false
// create empty stack

// for each vertex:
//     if vertex is not visited:
//         call DFS(vertex)

// while stack is not empty:
//     print stack.top()
//     pop stack



// DFS(node)

// mark node as visited

// for each neighbor of node:
//     if neighbor is not visited:
//         DFS(neighbor)

// push current node into stack



// Flow of Algorithm
// ---------------------------------------------
// Start
//   ↓
// Visit Node
//   ↓
// Visit All Neighbors Recursively
//   ↓
// Push Current Node into Stack
//   ↓
// Repeat for All Vertices
//   ↓
// Pop Stack
//   ↓
// Topological Order Obtained