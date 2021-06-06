/* Designing a Data Structure that act like wallet as PAYTM, in which user set his/her balance and get updated balance.
   So, with NAIVE method time comlexity is O(n) using pair of vectors, but using unordered map T.C is O(1) */
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> um;
int setBalance(int userId, int balance)
{
    um[userId] = balance;
    return 0;
}

int getBalance(int userId)
{
    auto it = um.find(userId);
    if(it != um.end())
        cout<< it ->second<<endl;
    else
        cout<<"No user with this Id"<<endl;
    return 0;
}

int main()
{
    setBalance(1,100);
    setBalance(2,2000);
    getBalance(1);
    setBalance(1,5000);
    getBalance(1);
    getBalance(2);
    setBalance(3,500);
    cout<<endl;
    setBalance(2,50000);
    getBalance(5);
}