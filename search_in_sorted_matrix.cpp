/* Searching an element in sorted row and column of a Matrix. Naive solution take O(R*C) time.
    */
#include<bits/stdc++.h>
using namespace std;
const int R=3;
const int C=3;

int searchMatNaive(int mat[R][C], int x){
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
            if(x == mat[i][j]){
                cout<<"Element found at index: "<<i<<" "<<j;
                break;
            }
        }
    return -1;
}

int main(){
    int mat[R][C] = {{10, 20, 30},
                     {15, 25, 35},
                     {32, 80, 100}
    };
    int x;
    cin>>x;
    searchMatNaive(mat, x);

}