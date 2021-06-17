#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap = true;

    bool compare(int a, int b){
        if(minHeap){
            return a < b;
        }
        else{
            return a > b;
        }
    }

    void heapify(int idx){       // Heapfy(index) will call heap property from parametrised index to leaf 
        int left = 2*idx;       //  Finding left and right child of given index
        int right = left + 1;

        int min_idx = idx;     // min_idx is used for getting minimum of root, left & right child
        int last = v.size() - 1;

        if(left <= last && compare(v[left], v[idx])){
            min_idx = left;
        }
        if(right <= last && compare(v[right], v[min_idx])){
            min_idx = right;
        }

        if(min_idx != idx){
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    // Constructor for initializing the Heap class
    Heap(int default_size = 10, bool type = true){
        v.reserve(default_size);
        v.push_back(-1);   // For blocking index 0 and start our execution from index 1
        minHeap = type;
    }
    void push(int d){
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;

        /* Keep Pushing to top till we reach root node or stop midway because current element is
           already placed at correct place */
        while(idx > 1 && compare(v[idx], v[parent])){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    int top(){      // Getting top element that is root
        return v[1];
    }

    void pop(){
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        return v.size() == 1;
    }
};

int main(){

    Heap h;   // If we take, h(10, false) then it behave like a MAX HEAP
    Heap max_h(10, false);
    int n;
    cin>>n;

    // Inserting element in MIN HEAP
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        h.push(ele);
    }
    cout<<"Min Heap is: ";
    // Removing element from MIN HEAP
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;

    // Inserting element in MAX HEAP
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        max_h.push(ele);
    }
    cout<<"Max Heap is: ";
    // Removing element from MAX HEAP
    while(!max_h.empty()){
        cout<<max_h.top()<<" ";
        max_h.pop();
    }

    return 0;
}