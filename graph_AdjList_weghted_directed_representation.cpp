#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
    /* Storing map's Key as source vertice in string and map's Value as List of Pair of destination 
    vertices and weight between them */
    map<string, list<pair<string, int>>> l;  

    public:
    //  Function for adding edges to the graph with giving it is bidirectional or not and with weight
        void addEdge(string src, string dstn, bool bidirec, int wt){
            l[src].push_back(make_pair(dstn, wt));
            if(bidirec){
                l[dstn].push_back(make_pair(src, wt)); // If edge is bidirectional then adding to both
            }
        }

        void printAdjList(){
            // Iterate over all the KEYS of map
            for(auto k:l){
                string city = k.first;
                list<pair<string, int>> nbrs = k.second;
                cout<<city<<"->";
                // Iterating over all the VALUES of map 
                for(auto nbr:nbrs){
                    string dest = nbr.first;
                    int dist = nbr.second;
                    cout<<"("<<dest<<","<<dist<<")";
                }
                cout<<endl;
            }
        }
};

int main(){
    Graph g;

    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "C", true, 10);
    g.addEdge("A", "D", false, 50);
    g.addEdge("B", "D", true, 30);
    g.addEdge("C", "D", true, 40);

    g.printAdjList();

    return 0;

}