/* In the question, it ask to find number of distinct elements present in subset of given array, we solve this using unoredered set 
    as unordered set count no. of distinct element and then we compare it with no. of elements a subset can have. Thus time complexity
        will be O(n) and space complexity is O(n) */
#include<bits/stdc++.h>
using namespace std;

int maxDistinct(int arr[], int size, int k)
{
    unordered_set<int> us;
    for (int i=0; i<size; i++)
    {
        us.insert(arr[i]);
    }
    if(us.size() >= size/k)
        cout<<"Number of Distinct elements are: "<<size/k;
    else
        cout<<"Number of Distinct elements are: "<<us.size();   

    return 0;
}

int main()
{
    int arr[]={1,1,2,3,1,5,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Array size is: "<<size<<endl;
    cout<<"Enter value of K that divide array size exactly: ";
    cin>> k;
    maxDistinct(arr, size, k);
    cout<<endl;
    
}