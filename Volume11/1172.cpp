#include<iostream>
using namespace std;

int main(){
    bool nonprime[300000] = {};
    nonprime[1] = true;
    for(int i = 2; i < 300000; i++){
        if(!nonprime[i]){
            for(int j = i+i; j < 300000; j += i)    nonprime[j] = true;
        }
    }

    int sum[300000] = {};
    for(int i = 1; i < 300000; i++) sum[i] = sum[i-1] + !nonprime[i];

    int n;
    while(cin >> n, n)  cout << sum[2*n] - sum[n] << endl;

    return 0;
}