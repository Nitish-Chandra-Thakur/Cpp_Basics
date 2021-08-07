#include<iostream>
#include<algorithm>
using namespace std;

int makeChanges(int *coin, int n, int money){
    int cnt=0;
    while(money > 0){
        // Getting the address for max value note,
        int idx = upper_bound(coin, coin+n, money)-1 - coin;
        money -= coin[idx];
        cnt++;
    }
    return cnt;
}

int main(){
    int money;
    cin>>money;
    
    int coin[] = {1,2,5,10,20,50,100,200,500,2000};
    int no_of_coin = sizeof(coin)/sizeof(int);

    cout<<"No. of coins needed is: "<<makeChanges(coin, no_of_coin, money);
    return 0;

}