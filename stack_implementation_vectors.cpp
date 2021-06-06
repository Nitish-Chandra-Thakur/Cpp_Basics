#include<iostream>
#include<vector>
using namespace std;

bool empty(vector<int> v){
    return v.size() == 0;
}
void push(vector<int> &v, int data){
    v.push_back(data);
}

void pop(vector<int> &v){
    if(!empty(v))
        v.pop_back();
}

void printStack(vector<int> v){
    int s = v.size()-1;
    while(s >=0){
        cout<<v[s]<<endl;
        s--;
    }
}
int main(){
    vector<int> v;

    push(v, 1);
    push(v, 2);
    push(v, 3);
    push(v, 4);
    push(v, 5);
    printStack(v);
    cout<<endl;
    pop(v);
    printStack(v);

}