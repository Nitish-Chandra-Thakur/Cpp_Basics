/* Problem - Given N ropes of different sizes, we have to join the ropes together. The cost of
   Joining 2 ropes of different sizes A and B is (A+B). Find the MINIMUM cost to join all ropes together. */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int joinRopes(int r[], int n){
    priority_queue<int, vector<int>, greater<int>> pq(r, r+n);      // Initialization of priority queue
    // for(int i=0; i<n; i++){
    //     pq.push(r[i]);
    // }
    int s1, s2;
    int cost = 0;
    while(pq.size() != 1){
        s1 = pq.top();      // Picking 1st minimum element
        pq.pop();           // After taking removing the same 
        s2 = pq.top();      // Picking 2nd minimum element
        pq.pop();           // After taking removing the same 
        cost += s1+s2;      // Finding cost of before cost and after calculation of two minimum element
        pq.push(s1+s2);     // Pushing the cost in priority queue after claculation
    }
    return cost;
}

int main(){
    int ropes[] = {4, 3, 2, 6};
    int n = 4;
    cout<<joinRopes(ropes, n)<<endl;
}