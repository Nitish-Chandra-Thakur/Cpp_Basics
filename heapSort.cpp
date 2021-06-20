/* Implementing HEAPSORT using Max Heap. It take O(NlogN) time in best, average and worst case  */
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &v, int idx, int size){
    int left = 2*idx;
    int right = left + 1;

    int largest = idx;
    int last = size-1;

    if(left <= last && v[idx] < v[left]){
        largest = left;
    }
    if(right <= last && v[largest] < v[right]){
        largest = right;
    }

    if(idx != largest){
        swap(v[idx], v[largest]);
        heapify(v, largest, size);
    }
}

void buildHeap(vector<int> &v){
    // This loop run from 1st non-leaf node to root node
    for(int i = (v.size() - 1)/2; i>=1; i--){  
        heapify(v, i, v.size());
    }
}

void heapSort(vector<int> &v){
    buildHeap(v);
    int n = v.size();
    //remove n-1 elements from the heap
    while(n>1){
        swap(v[1], v[n-1]);
        n--;           // Remove the top element from the Heap
        heapify(v, 1, n);
    }
}

void print(const vector<int> &v){
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    vector<int> v;
    v.push_back(-1);
    int n;
    cin>>n;

    int temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
    }

    heapSort(v);
    print(v);
    cout<<endl;

    return 0;
}