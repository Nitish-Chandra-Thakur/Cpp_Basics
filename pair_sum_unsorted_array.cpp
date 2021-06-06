/* From given array we have to find the pair sum equal to given sum, so for NAIVE solution time complexity 
   is O(n^2), but using unorded set will give solution in O(n) time and O(n) auxilliary space*/
#include<bits/stdc++.h>
using namespace std;

int pairSumNaive(int arr[], int n, int sum)
{
    for (int i=0; i<n; i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if(arr[i]+arr[j] == sum)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"No pair sum";
    return 0;
}

bool pairSumEfficient(int arr[], int n, int sum)
{
    unordered_set<int> us;
    for (int i=0; i<n; i++)
    {
        if(us.find(sum-arr[i]) != us.end())
        {
            cout<<"YES";
            return true;
        }
        else
            us.insert(arr[i]);
    }
    cout<<"No pair sum";
    return false;
}

int main()
{
    int arr[]={3,2,8,15,-8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum = 17;
    int arr1[]={2,4,6,3};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int sum1 = 11;
    int arr2[]={5,8,-3,6};
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int sum2 = 3;
    pairSumNaive(arr, size, sum);
    cout<<endl;
    pairSumNaive(arr1, size1, sum1);
    cout<<endl;
    pairSumNaive(arr2, size2, sum2);
    cout<<endl;
    pairSumEfficient(arr, size, sum);
    cout<<endl;
    pairSumEfficient(arr1, size1, sum1);
    cout<<endl;

}