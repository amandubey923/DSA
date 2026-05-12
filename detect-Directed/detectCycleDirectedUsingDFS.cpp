#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
    }

    bool isCycleDirDFS(int curr, vector<bool> &vis, vector<bool> &reccursionPath){
        vis[curr] = true;
        reccursionPath[curr] = true;

        for(int v: l[curr]){
           if(!vis[v]){
            if(isCycleDirDFS(v, vis, reccursionPath)){
                return true;
            }
           }else if(reccursionPath[v]){
            return true;
           }
           
        }
        reccursionPath[curr] = false;
        return false;

    } 

    bool isCycle(){
        vector<bool> vis(V, false);
        vector<bool> reccursionPath(V, false);

        for (int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycleDirDFS(i, vis, reccursionPath)){
                    return true;
                }
            }
        }
        return false;
    }
 
};
int main(){
    Graph g(4);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);


    cout<<"Cycle Present or Not: "<<g.isCycle()<<endl; 
   

    return 0;   
}

/*
---------------------------------------------------------
Cycle Detection in Directed Graph using DFS
---------------------------------------------------------
Definition:
Cycle Detection means checking whether
a directed graph contains a cycle or not.
A cycle exists if we can return to the
same node again while traversing the graph.
This algorithm works only for:
1. Directed Graph
2. DFS Traversal
---------------------------------------------------------
Main Idea
---------------------------------------------------------
During DFS traversal:
1. Mark current node as visited.
2. Mark current node in recursion path.
3. Visit all neighbors recursively.
4. If a neighbor is already present
   in current recursion path,
   then cycle exists.
5. After DFS completion,
   remove node from recursion path.
---------------------------------------------------------
Why Recursion Path Array is Used
---------------------------------------------------------
visited[]:
Checks whether node was visited before.
recursionPath[]:
Checks whether node is part of
current DFS call stack.
If a node is already in recursion path,
then graph contains back edge,
which means cycle exists.
---------------------------------------------------------
Data Structures Used
---------------------------------------------------------
1. Adjacency List
-------------------------
list<int> *l;
Stores graph connections.
2. Visited Array
-------------------------
vector<bool> vis;
Tracks visited nodes.
3. Recursion Path Array
-------------------------
vector<bool> recursionPath;

Tracks nodes currently present
in DFS recursion stack.
---------------------------------------------------------
DFS Function Logic
---------------------------------------------------------
Step 1:
Mark current node as visited.

Step 2:
Mark current node in recursion path.

Step 3:
Traverse all adjacent neighbors.

Step 4:
If neighbor is unvisited:
    Call DFS recursively.

Step 5:
If neighbor already exists
in recursion path:
    Cycle detected.

Step 6:
After traversal,
remove current node
from recursion path.


---------------------------------------------------------
Cycle Detection Condition
---------------------------------------------------------

If recursionPath[v] == true

then cycle exists.


---------------------------------------------------------
Time Complexity
---------------------------------------------------------

O(V + E)

V = Number of Vertices
E = Number of Edges


---------------------------------------------------------
Space Complexity
---------------------------------------------------------

O(V)

Used for:
1. Visited Array
2. Recursion Path Array
3. Recursion Stack


---------------------------------------------------------
Example Graph
---------------------------------------------------------

1 -> 0
0 -> 2
2 -> 3
3 -> 0

Cycle:
0 -> 2 -> 3 -> 0


---------------------------------------------------------
Output
---------------------------------------------------------

Cycle Present or Not: 1
1 means cycle exists.
0 means no cycle.
---------------------------------------------------------
Pseudo Code
---------------------------------------------------------

Function isCycle():
    create visited array
    create recursionPath array
    for each vertex:
        if vertex is not visited:
            if DFS(vertex):
                return true
    return false
Function DFS(node):
    mark node visited
    mark node in recursionPath
    for each neighbor:
        if neighbor not visited:
            if DFS(neighbor):
                return true
        else if neighbor exists
        in recursionPath:
            return true

    remove node from recursionPath
    return false
---------------------------------------------------------
Flow of Algorithm
---------------------------------------------------------

Start
  ↓
Visit Node
  ↓
Mark in Recursion Path
  ↓
Visit All Neighbors
  ↓
Neighbor Already in Recursion Path?
  ↓
Yes → Cycle Found
  ↓
No
  ↓
Remove Node from Recursion Path
  ↓
Continue DFS
  ↓
Finish
---------------------------------------------------------
Important Points
---------------------------------------------------------

1. Works only for Directed Graph.

2. Uses DFS Traversal.

3. Back Edge indicates cycle.

4. recursionPath array is important.

5. If cycle exists,
   topological sorting is not possible.
---------------------------------------------------------
*/