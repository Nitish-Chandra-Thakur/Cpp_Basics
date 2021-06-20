/* Finding the MEDIAN of the running stream of intergers.*/
#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> leftheap;  //Max Heap for left part
    priority_queue<int, vector<int>, greater<int>> rightheap;  //Min Heap for right part

    int d;
    cin>>d;
    leftheap.push(d);
    // Finding Median of first element explicitly
    float med = d;
    cout<<"Median is "<<med<<endl;
    cin>>d;
    while(d != -1){     //Condition for taking stream of integers, till we get -1 as input
        if(leftheap.size() > rightheap.size()){
            if(d < med){
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else{
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }

        else if(leftheap.size() == rightheap.size()){
            if(d < med){
                leftheap.push(d);
                med = leftheap.top();
            }
            else{
                rightheap.push(d);
                med = rightheap.top();
            }
        }
        else{
            if(d > med){
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            else{
                leftheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }
        cout<<"Median is: "<<med;
        cin>>d;
    }   
    return 0;
}