#include<iostream>
using namespace std;

bool subSetTD(int set[], int sum, int n){
    int t[n+1][sum+1];

    // Initilization of the matrix for TOP DOWN
    for(int i=0; i<n; i++){
        for(int j=0; j<sum; j++){
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(set[i-1] <= sum)
                t[i][j] = t[i-1][j - set[i-1]] || t[i-1][j];

            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}


int main(){
    int set[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 9;
    int n = sizeof(set)/sizeof(n);
    if(subSetTD(set, sum, n)){
        cout<<"Subset is possible - - - TRUE!!!";
    }
    else{
        cout<<"Subset is Not possible - - - FALSE!!!";
    }

    return 0;

}