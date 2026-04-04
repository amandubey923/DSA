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
        l[u].push_back(v);
        l[v].push_back(u);

    }
    void printAdjList(){
        for(int i=0; i<V; i++){
            cout<<i<<":";
            for(int neigh: l[i]){
                cout<<neigh<<",";
            }
            cout<<endl;
        }
    }

       //BFS traversal
    void bfs(){
        queue<int> Q;
        vector<bool> visited(V, false);

        Q.push(0); // source node
        visited[0] = true;

        while(Q.size()>0){
            int u = Q.front(); // u->v
            Q.pop();

            cout<<u<<" ";

            for(int v: l[u]){  // v -> immediate neigh of u
                if(!visited[v]){
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }
    //DFS Traversal
    void dfsHelper(int u , vector<bool> &visited){
        cout<< u <<"";
        visited[u]= true;

        for(int v: l[u]){
            if(!visited[v]){
                dfsHelper(v, visited);
            }
        }
    }

    void dfs(){
        int src = 0;
        vector<bool> visited(V, false);
        dfsHelper(src, visited);

        cout<<endl;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    
    // g.printAdjList();
    cout<<"DFS Traversal: ";
    g.dfs();

    cout<<"BFS Traversal: ";
    g.bfs();

    return 0;   
}