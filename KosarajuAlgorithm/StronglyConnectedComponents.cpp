#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    public:
    vector<vector<int>> adj;
    int V;
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void topologicalSort(int curr, vector<bool> &visited, stack<int> &s){
        visited[curr] = true;
        for(auto neighbor: adj[curr]){
            if(!visited[neighbor]){
                topologicalSort(neighbor, visited, s);
            }
        }
        s.push(curr);
    }

    void dfs(int curr, vector<bool> &visited, vector<vector<int>> &revAdj){
        visited[curr] = true;
        cout << curr << " "; // print the current node in the SCC
        for(auto neighbor: revAdj[curr]){
            if(!visited[neighbor]){
                dfs(neighbor, visited, revAdj);
            }
        }
    }

    void kosaraju(){
        // step 1: DFS and fill stack
        stack<int> s;
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topologicalSort(i, visited, s);
            }
        }
        
        // step 2: reverse(transpose) the graph
        vector<vector<int>> revAdj(V);
        for(int u=0; u<V; u++){ // u-->v
            visited[u] = false; // reset visited for next DFS
            for(auto v: adj[u]){
                revAdj[v].push_back(u); // v-->u
            }
        }
        cout << "Strongly Connected Components are:" << endl;
        
        // step 3: DFS on reversed graph in order of stack
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            if(!visited[curr]){
                dfs(curr, visited, revAdj);
                cout << endl; // print a new line after each SCC
            }
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);

    g.kosaraju();
    return 0;
}