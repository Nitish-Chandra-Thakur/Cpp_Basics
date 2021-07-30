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
        l[x].push_back(y);        // As Topological graph is directed graph
    }

    void topological_sort(){
        int *indegree = new int[v];
        // Initializing every node as indegree 0
        for(int i=0; i<v; i++){
            indegree[i] = 0;
        }
        // update indegree by traversing the edges
        for(int i=0; i<v; i++){
            for(auto y:l[i]){
                indegree[y]++;
            }
        }

        queue<int> q;
        // Using bfs for traversing the graph
        // Step-1. finding the nodes with indgree 0
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto nbr:l[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.topological_sort();
    return 0;
}