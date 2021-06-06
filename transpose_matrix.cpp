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
    for(int i=0; i<C; i++){
        for(int j=0; j<R; j++)
            cout<<mat[j][i]<<" ";
        cout<<endl;
    }
}