#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "XYZ";
    int n = str.size();
    int count = 1 << n;
    for(int i=0; i<count; i++){
        for(int j=0; j<n; j++)
            if((i & (1 << j)) > 0)
                cout<<str[j];
        cout<<" ";
    }
}