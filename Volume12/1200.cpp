#include<iostream>
using namespace std;

int main(){
    bool nonprime[1<<15] = {};
    nonprime[0] = nonprime[1] = true;

    for(int i = 2; i < 1<<15; i++){
        if(nonprime[i]) continue;
        for(int j = i+i; j < 1<<15; j+=i)   nonprime[j] = true;
    }

    int n;
    while(cin >> n, n){
        int cnt = 0;
        for(int i = 2; i+i <= n; i++){
            if(!nonprime[i] && !nonprime[n-i])  cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}