/* Implementing a DATA STRUCTURE that have to perform add(price, item), find(price), printsorted(price), printGreatersorted(price)
   and printSmallersorted(price) where price of entity is distinct. */
#include<bits\stdc++.h>
using namespace std;

map<int,string> m;
int addItem(int price, string item)
{
    m.insert({price, item});
    return 0;
}

int findItem(int price)
{
    if(m.count(price))
    {
        for(auto &x:m)
        {
            cout<< x. second<<endl;
            break;
        }
    }
    else
        cout<<"No item at this price"<<endl;
    return 0;
}

int printSorted()
{
    for(auto &x:m)
        cout<< x.second<<" "<<x.first<<endl;
    return 0;
}

int printGreaterSorted(int price)
{
    auto it = m.upper_bound(price);
    while (it != m.end())
    {
        cout<< it->second<<" "<<it->first<<endl;
        it++;
    }
    return 0;
}

int printSmallerSorted(int price)
{
    auto it = m.lower_bound(price);
    for (auto it1=m.begin(); it1 != it; it1++)
    {
        cout<<it1->second<<" "<<it1->first<<endl;
    }
    return 0;
}

int main()
{
    addItem(10,"ABC");
    addItem(5, "XYZ");
    addItem(100, "PQR");
    findItem(5);
    printSorted();
    printGreaterSorted(7);
    printSmallerSorted(20);
}