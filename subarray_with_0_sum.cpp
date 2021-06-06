/* We need to find subarry(contiguous elements) with sum of that subarray is 0, so NAIVE solution 
   take O(n^2) time complexity, but using hashing(unordered set) concept with prefix sum(cumulative sum) 
   then time complexity & space complexity is O(n) */
#include<bits/stdc++.h>
using namespace std;

bool subarrayNaive(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        int sum = 0;
        sum = sum + arr[i];
        if(sum == 0)
            return true;
        else
        {
            for (int j=i+1; j<size; j++)
            {
            sum = sum+arr[j];
            if(sum == 0)
                return true;
            }
        }
    }
    return false;
}

bool isZerosubarrayEfficient(int arr[], int n)
{
    unordered_set<int> us;
    int pre_sum = 0;
    us.insert(0);
    for (int i=0; i<n; i++)
    {
        pre_sum = pre_sum + arr[i];
        if(us.find(pre_sum) != us.end())
            return true;
        if(pre_sum == 0)
            return true;
        us.insert(pre_sum);
    }
    return false;
}

int main()
{
    int arr[]={5,6,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int arr1[]={1,4,13,-3,-10,5};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={3,-1,-2,5,6};  
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int arr3[]={1,4,-3,1,2};
    int size3=sizeof(arr3)/sizeof(arr3[0]);

    cout<<subarrayNaive(arr, size);
    cout<<endl;

    cout<<subarrayNaive(arr1, size1);
    cout<<endl;

    cout<<subarrayNaive(arr2, size2);
    cout<<endl;

    cout<<subarrayNaive(arr3, size3);
    cout<<endl;

    cout<<isZerosubarrayEfficient(arr, size);
    cout<<endl;

    cout<<isZerosubarrayEfficient(arr1, size1);
    cout<<endl;

    cout<<isZerosubarrayEfficient(arr2, size2);
    cout<<endl;

    cout<<isZerosubarrayEfficient(arr3, size3);
    cout<<endl;
}