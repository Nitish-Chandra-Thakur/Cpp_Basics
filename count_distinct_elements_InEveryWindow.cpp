#include<bits/stdc++.h>
using namespace std;

int countDistinctNaive(int arr[], int n, int k)
{
    for(int i=0;i<=n-k;i++)
    {
        int count = 0;
        for(int j=0;j<k;j++)
        {
            bool flag=false;
            for(int p=0;p<j;p++)
            {
                if(arr[i+j] == arr[i+p])
                {
                    flag=true;
                    break;
                }
            }
            if(flag == false)
                count++;
        }
        cout<<count<<" ";
    }
    return 0;
}

void countDistinctEfficient(int arr[], int n, int k)
{
    unordered_map<int,int> freq;
    for(int i=0;i<k;i++)
        freq[arr[i]]++;
    cout<<freq.size()<<" ";
    for(int i=k;i<n;i++)
    {
        freq[arr[i-k]]--;
        if(freq[arr[i-k]] == 0)
            freq.erase(arr[i-k]);
        freq[arr[i]]++;
        cout<<freq.size()<<" ";
    }
}

int main()
{
    int arr[]={10,20,20,10,30,40,10};
    int size=sizeof(arr)/sizeof(arr[0]);

    int k;
    cout<<"Enter Value of window K <= size: ";
    cin>>k;

    countDistinctNaive(arr, size, k);
    cout<<endl;
    countDistinctEfficient(arr, size, k);


}