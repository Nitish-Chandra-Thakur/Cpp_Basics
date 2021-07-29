#include<iostream>
#include<list>
using namespace std;

class Graph{
    int v;      // Storing number of vertices in Graph
    list<int> *l;       // Storing list of edges, declare it as pointer 

public:
    Graph(int ver){
        v = ver;        // Taking verctices 
        l = new list<int> [v];      // Creating dynamic Array of List
    }

// Function for adding undirected edges to the graph
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

// Function for printing the graph as Adjacency List of graph
    void printAdjList(){
        // Iterate over all vertices
        for(int i=0; i<v; i++){
            cout<<"Vertices "<<i<<"->";
            for(int nbr:l[i]){      // Iterating over the List of Edges
                cout<<"["<<nbr<<"]";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);     // Graph class variable with 4 vertices
    g.addEdge(0,1);     // Adding edge to given graph
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printAdjList();       // Printing Adjacency List of graph
    return 0;
}