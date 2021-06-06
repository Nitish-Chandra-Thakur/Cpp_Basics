/* Implementing Sorting using priority queue */
#include<bits/stdc++.h>
using namespace std;

int PQsort(int *arr, int size)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+size);
    while(pq.empty() == false)
    {
        cout<< pq.top() << " ";
        pq.pop();
    }
    return 0;
}
int main()
{
    int arr[] = {5,10,3,12,7,18,13, 10, 19, 13, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    PQsort(arr, size);
    return 0;
}