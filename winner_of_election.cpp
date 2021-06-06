#include<bits/stdc++.h>
using namespace std;

int winnerName(string arr[], int size)
{
    unordered_map<string,int> um;
    for (int i = 0; i < size; i++)
        um[arr[i]]++;
    int count=0;
    string winner;
    for(auto x:um)
    {
        if(x.second > count)
        {
            count = x.second;
            winner = x.first;
        }
        else if(x.second == count && x.first < winner)
            winner = x.first;
    }
    cout<< winner;
    return 0;
}
int main()
{
    string arr[] = {"Raja", "Monu", "Monu", "Sonu","Raja"};
    int size = sizeof(arr)/sizeof(arr[0]);
    winnerName(arr, size);

}