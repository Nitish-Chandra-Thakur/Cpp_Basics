#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;

    public:
        void addEdge(T x, T y){
            l[x].push_back(y);
            l[y].push_back(x);
    }

        void bfs(T src){
            map<T, bool> visited;
            queue<T> q;
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                T vertices = q.front();
                q.pop();
                cout<<vertices<<" ";
                for(auto nbr:l[vertices]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        // Mark neighbour as visited
                        visited[nbr] = true;
                    }
                }
            }
        }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);

    return 0;
}