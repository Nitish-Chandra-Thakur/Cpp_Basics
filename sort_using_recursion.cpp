#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insert(vector<int> &arr, int temp){
    if(arr.size() == 0 || arr[arr.size() - 1] <=  temp){
        arr.push_back(temp);
        return;
    }
    
    int val = arr[arr.size() - 1];
    arr.pop_back();
    insert(arr, temp);
    arr.push_back(val);

    return;
}

void sorting(vector<int> &arr){
    if(arr.size() == 1)
        return;
    int temp = arr[arr.size() - 1];
    arr.pop_back();
    sorting(arr);
    insert(arr, temp);
    //arr.push_back(temp);

    return;
}

int main(){
    vector<int> arr = {2,3,7,6,4,9,5};
    int n = arr.size();

    sorting(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}