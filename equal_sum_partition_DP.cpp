#include<iostream>
using namespace std;

bool subSetSum(int arr[], int sum, int n){
    int t[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;

            if(arr[i-1] <= sum)
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
            else 
                t[i][j] = t[i-1][j];
            
        }
    }
    return t[n][sum];
}

bool equalSumPartitionTD(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    if(sum % 2 != 0)
        return false;

    else if(sum % 2 == 0)
        return subSetSum(arr, sum/2, n);
}

int main(){
    int arr[] = {1, 5, 11, 6};
    int n = sizeof(arr)/sizeof(int);

    if(equalSumPartitionTD(arr, n))
        cout<<"Equal Sum Partition is Possible!!!!"<<endl;
    else
        cout<<"Equal Sum Partition is Not Possible!!!"<<endl;

    return 0;
}
