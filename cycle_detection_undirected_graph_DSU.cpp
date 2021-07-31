#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int, int>> l;
public:
    Graph(int v){
        this -> v = v;
    }

    void addEdge(int u, int v){
        l.push_back(make_pair(u,v));
    }

    // Find Function 
    int find_ele(int i, int parent[]){
        //Base condition
        if(parent[i] == -1){
            return i;
        }
        return find_ele(parent[i], parent);
    }

    void union_set(int x, int y, int parent[]){
        int s1 = find_ele(x, parent);
        int s2 = find_ele(y, parent);

        if(s1 != s2){
            parent[s2] = s1;
        }
    }

    bool contain_cycle(){
        int *parent = new int[v];
        for(int i=0; i<v; i++){
            parent[i] = -1;
        }

        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;

            int s1 = find_ele(i, parent);
            int s2 = find_ele(j, parent);

            if(s1 != s2){
                union_set(s1, s2, parent);
            }
            else{
                return true;
            }
        }
        delete [] parent;
        return false;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    //g.addEdge(3, 0);

    if(g.contain_cycle()){
        cout<<"Graph contain a CYCLE";
    }
    else{
        cout<<"Graph does NOT contain Cycle";
    }

    return 0;
}