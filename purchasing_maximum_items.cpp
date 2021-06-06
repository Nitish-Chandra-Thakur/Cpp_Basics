/* Finding the maximum number of items to be purchased from a given cart of Array
   with fixed amount of sum, better than sorting method as it take O(nlogn) time while 
   min heap takes O(n)+ O(count*logn) time on an average and in worst case it take O(n)+O(nlogn) time when all items to be pick */

#include<bits/stdc++.h>
using namespace std;

int maxitems(int arr[], int size, int sum)
{
    int count=0;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+size);
    while(sum>=0 && sum >= pq.top() && pq.empty() == false)
    {
            sum = sum - pq.top();
            pq.pop();
            count++;
    }
    return count;
}
int main()
{
    int cost[] = {20, 10, 5, 30, 100};
    int sum = 35;
    int size = sizeof(cost)/sizeof(cost[0]);
    cout << "Maximum item we purchase is: "<<maxitems(cost, size, sum);
    return 0;

}