#include<bits/stdc++.h>
using namespace std;

void maxKarray(int arr[], int n, int k)
{
    for(int i=0; i< n-k+1; i++)
    {
        int mx=arr[i];
        for(int j=i+1; j<k+i;j++)
            if(mx < arr[j])
            {
                mx = arr[j];     //mx = max(arr[j], mx);
            }
        cout<< mx << " ";
    }
}

int main()
{
    int arr[] = {10,8,5,12,15,7,6,17};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< "Size of arrays is: "<<n<<endl;
    int k;
    cout<< "Enter value of subarray less than equal to n: ";
    cin>> k;
    maxKarray(arr, n, k);
    return 0;
}
