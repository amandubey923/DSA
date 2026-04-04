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