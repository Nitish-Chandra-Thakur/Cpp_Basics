#include<iostream>
#include<queue>
#include<list>
#include<map>
#include<climits>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;

    public:
        void addEdge(T x, T y){
            l[x].push_back(y);
            l[y].push_back(x);
        } 

        void bfs_sssp(T src){
            map<T, int> dist;
            queue<T> q;

            // All other node will have INT_MAX
            for(auto node_pair:l){
                T node = node_pair.first;
                dist[node] = INT_MAX;
            }
            q.push(src);
            dist[src] = 0;
            
            while(!q.empty()){
                T node = q.front();
                q.pop();

                for(auto nbr:l[node]){
                    if(dist[nbr] == INT_MAX){
                        q.push(nbr);
                        // mark that neighbour as visited
                        dist[nbr] = dist[node] + 1;
                    }
                }
            }

            // print distance of every node
            for(auto node_pair:l){
                T node = node_pair.first;
                int d = dist[node];
                cout<<"Node "<<node<<" distance from source is "<<d<<endl;
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

    g.bfs_sssp(0);
    return 0;
}