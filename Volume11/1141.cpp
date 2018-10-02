#include<iostream>
using namespace std;

int main(){
    bool nonprime[1000000] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i < 1000000; i++){
        if(!nonprime[i]){
            for(int j = i+i; j < 1000000; j+=i) nonprime[j] = true;
        }
    }

    int a, d, n;
    while(cin >> a >> d >> n, a+d+n){
        while(1){
            if(!nonprime[a])    n--;
            if(n == 0)  break;
            a += d;
        }
        cout << a << endl;
    }
    return 0;
}