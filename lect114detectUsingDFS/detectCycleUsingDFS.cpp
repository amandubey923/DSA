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

    bool isCycleUndirDFS(int src, int par, vector<bool> &vis){
        vis[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors){
            if(!vis[v]){
                if(isCycleUndirDFS(v, src, vis)){
                    return true;
                }
            }else if(v != par){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);

        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(isCycleUndirDFS(i, -1, vis)){
                    return true;
                }
            }
        }
        return false;

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
    //g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    
    cout<< g.isCycle()<<endl;

   

    return 0;   
}