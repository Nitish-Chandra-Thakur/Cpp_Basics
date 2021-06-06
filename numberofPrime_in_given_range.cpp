#include <iostream>
#include<math.h>
using namespace std;

bool isPrime(int n){
    if(n==1)
        return false;
    if(n==2)
        return true;
    for(int i=2; i<=sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

//Write your totalPrime function here
int totalPrime(int l, int h){
    int count = 0;
    for(int i=l; i<=h; i++){
        if(isPrime(i))
            count++;
    }
    return count;
}

int main() {
    int S, E;
    cin >> S >> E;
    cout << totalPrime(S, E);
    return 0;
}