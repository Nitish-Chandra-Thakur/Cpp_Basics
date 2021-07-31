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

    void addEdge(int x, int y, bool directed=true){
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);
        }
    }

    bool cycle_helper(int node, bool *visited, bool *stack){
        // Visiting a node
        visited[node] = true;
        stack[node] = true;

        for(int nbr:l[node]){
            if(stack[nbr] == true){
                return true;
            }
            else if(visited[nbr] == false){
                bool cycle_mila = cycle_helper(nbr, visited, stack);
                if(cycle_mila == true){
                    return true;
                }
            }
        }
        stack[node] = false;
        return false;
    }
    bool cycle_detection(){
        bool *visited = new bool[v];
        bool *stack = new bool[v];

        for(int i=0; i<v; i++){
            visited[i] = stack[i] = false;
        }

        return cycle_helper(0, visited, stack);
    }
};

int main(){
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);    // BACK EDGE

    if(g.cycle_detection()){
        cout<<"Graph contain Cycle";
    }
    else{
        cout<<"Graph does NOT contain Cycle";
    }
    return 0;   
}