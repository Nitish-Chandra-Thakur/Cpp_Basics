/* Finding the Intersection of given two array, as NAIVE solution take O(n^2) time complexity, where as SET concept take
    O(sizeA + sizeB) time complexity and O(sizeB) space complexity */
#include<bits/stdc++.h>
using namespace std;

int intersection(int arrA[], int arrB[], int sizeA, int sizeB)
{
    unordered_set<int> usB;
    for(int i=0; i<sizeB; i++)
        usB.insert(arrB[i]);
    
    for (int i=0; i<sizeA; i++)
    {
        if(usB.find(arrA[i]) != usB.end())
            cout<<arrA[i]<<" ";
    }
    return 0;
}
int main()
{
    int arrA[]={10,15,20,25,30,50};
    int arrB[]={30,5,15,80};
    int sizeA=sizeof(arrA)/sizeof(arrA[0]);
    int sizeB=sizeof(arrB)/sizeof(arrB[0]);
    intersection(arrA, arrB, sizeA, sizeB);
}