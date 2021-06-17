#include<iostream>
#include<vector>
using namespace std;

bool minHeap = false;  // Taking false for making Array/vector as Max Heap

// This function used for both min heap and max heap for comparision root & its child node
bool compare(int a, int b){
    if(minHeap){
        return a > b;
    }
    else{
        return a < b;
    }
}

// Heapify is a recursive call, that work on node till it reach its correct position
void heapify(vector<int> &v, int idx){
    int left = 2*idx;
    int right = left + 1;

    int min_idx = idx;
    int last = v.size() - 1;

    if(left <= last && compare(v[idx], v[left])){
        min_idx = left;
    }
    if(right <= last && compare(v[min_idx], v[right])){
        min_idx = right;
    }

    if(idx != min_idx){
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

// Function for printing vector elements
void print(vector<int> &v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

// Function for building MAX-HEAP. It will take O(NlogN) time
void buildHeapNaive(vector<int> &v){
    for(int i=2; i<v.size(); i++){      // for loop start from 2nd element of heap, as 1st element is always a heap
        int idx = i;
        int parent = i/2;
        while(idx > 1 && v[idx] > v[parent]){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
}

// Function for building HEAP. It will take O(N) time
void buildHeapOptimised(vector<int> &v){
    // This loop run from 1st non-leaf node to root node
    for(int i = (v.size() - 1)/2; i>=1; i--){  
        heapify(v, i);
    }
}

int main(){
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};      // For Blocking 0th index, i write 1st element -1
    print(v);

    buildHeapNaive(v);
    print(v);
    cout<<endl;

    buildHeapOptimised(v);
    print(v);
    cout<<endl;


    return 0;
}