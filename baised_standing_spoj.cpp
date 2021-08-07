#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int arr[20] = {0};
    int n;
    cin>>n;
    string name;
    int rank;
    for(int i=0;i <n; i++){
        cin>>name>>rank;
        arr[rank]++;
    }

    int actual_rank = 1;
    int sum = 0;
    for(int i=1; i<=n; i++){
        while(arr[i]){
            sum += abs(actual_rank-i);
            arr[i]--;
            actual_rank++;
        }
    }

    cout<<sum;
}