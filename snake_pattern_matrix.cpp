#include<bits/stdc++.h>
using namespace std;
int R = 5;
int C = 3;
int main(){
    int mat[R][C] = {{1,2,3},
                   {4,5,6},
                   {7,8,9},
                   {10,11,12},
                   {13,14,15}
    };
    for(int i=0; i<R; i++){
        if(i % 2 == 0)
            for(int j=0; j<C; j++)
                cout<<mat[i][j]<<" ";
        else
            for(int j=C-1; j>=0; j--)
                cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}