#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;
    public:
        void addEdge(T x, T y){
            l[x].push_back(y);      // As Topological sorting is directed graph
        }

        void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering){
            visited[src] = true;
            for(T nbr:l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr, visited, ordering);
                }
            }
            ordering.push_front(src);
            return;
        }
        void dfs(){
            map<T, bool> visited;
            list<T> ordering;
            for(auto p:l){
                T node = p.first;
                visited[node] = false;
            }
            for(auto p:l){
                T node = p.first;
                if(!visited[node]){
                    dfs_helper(node, visited, ordering);
                }
            }
            for(auto node:ordering){
                cout<<node<<endl;
            }
        }
};

int main(){
    Graph<string> g;
    g.addEdge("Python", "DataProcessing");
    g.addEdge("Python", "PyTroch");
    g.addEdge("Python", "ML");
    g.addEdge("DataProcessing", "ML");
    g.addEdge("PyTroch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("Dataset", "FaceRecogn");

    g.dfs();
    return 0;
}