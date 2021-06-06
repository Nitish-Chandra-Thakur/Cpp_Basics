/* Finding the k largest elements from the given array*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int size = sizeof(arr)/sizeof(arr[0]);  //this take O(n) time
    int k;
    cout<< "Enter K value: ";
    cin>> k;

    /*priority_queue<int> pq(arr, arr+size);
    for(int i=0; i<k;i++)
    {
        cout<< pq.top() <<" ";
        pq.pop();                           //this take O(klogn) time
    }*/                                    //so total time O(n + klogn)  

// sorting Using Min heap that take O(k + (n-k)*logk)

    priority_queue<int, vector<int>, greater<int>> pqm(arr, arr+k);
    for(int i=k; i<size; i++)
    {
        if(arr[i] > pqm.top())
        {
            pqm.pop();
            pqm.push(arr[i]);
        }
    }
    while(pqm.empty() == false)
    {
        cout<<pqm.top() << " ";
        pqm.pop();
    }
    return 0;
}