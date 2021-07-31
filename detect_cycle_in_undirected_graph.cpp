#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int v;
public:
    Graph(int ver){
        v = ver;
        l = new list<int>[v];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool is_tree(){
        bool *visited = new bool[v];
        int *parent = new int[v];
        queue<int> q;

        // Initializing the node with visited = false and parent of every node is itself
        for(int i=0; i<v; i++){
            visited[i] = false;
            parent[i] = i;
        }
        int src = 0;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr:l[node]){
                if(visited[nbr] == true && parent[node] != nbr){
                    return false;
                }
                else if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    //g.addEdge(0, 3);

    if(g.is_tree()){
        cout<<"Given graph is TREE";
    }
    else{
        cout<<"Given graph is NOT TREE";
    }

    return 0;
}