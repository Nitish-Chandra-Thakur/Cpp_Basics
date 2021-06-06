/* Implementing a DATA STRUCTURE that have to perform add(price, item), find(price), printsorted(price), printGreatersorted(price)
   and printSmallersorted(price) where same price exists more than one too (i.e. price duplication is allow) */
#include<bits/stdc++.h>
using namespace std;

multimap<int,string> mp;
void addItem(int price, string item)
{
    mp.insert({price, item});
}

int findItem(int price)
{
    auto it=mp.find(price);
    while(it -> first == price)
    {
        cout<< it->second<<" "<<it->first<<endl;
        it++;
    }
    if(it->first != price)
        cout<<"No item at this price"<<endl;
    return 0;
}

int printSorted()
{
    for(auto &x:mp)
    {
        cout<<x.second<<" "<<x.first<<endl;
    }
    return 0;
}

int printGreaterSorted(int price)
{
    auto it = mp.upper_bound(price);
    while(it != mp.end())
    {
        cout<<it->second<<" "<<it->first<<endl;
        it++;
    }
    return 0;
}

int printSmallerSorted(int price)
{
    auto it = mp.lower_bound(price);
    for(auto it1=mp.begin(); it1->first != it->first; it1++)
    {
        cout<<it1->second<<" "<<it1->first<<endl;
    }
    return 0;
}

int main()
{
    addItem(10,"Bread");
    addItem(20, "Chocolate");
    addItem(5, "Biscuit");
    addItem(10, "Icecream");
    addItem(20, "Snacks");

    findItem(50);
    cout<<endl;
    printSorted();
    cout<<endl;
    printGreaterSorted(10);
    cout<<endl;
    printSmallerSorted(5);
}