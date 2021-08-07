#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[100];
    int n, i, diff, val;

    while(true){
        int max_load=0, load=0;
        cin>>n;
        //stop taking input if n == -1
        if(n == -1)
            break;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            load += arr[i];
        }
        if(load % n != 0){
            cout<<"Not possible load balancing";
            continue;
        }

        //Find the load that equally to be distributed
        load = load / n;
        diff = 0;

        //greedy step
        for(int i=0; i<n; i++){
        //finding diff b/w final load to be assigned and the current load
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout<<"Equally distributed load take: "<<max_load<<" transfers."<<endl;
    }
}