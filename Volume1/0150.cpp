#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    // preparation
    bool nonprime[10001] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i < 10001; i++){
        if(!nonprime[i]){
            for(int j = i+i; j < 10001; j += i){
                nonprime[j] = true;
            }
        }
    }

    int n;
    while(cin >> n){
        if(n == 0)  break;

        int large;
        for(large = n; ; large--){
            if(!nonprime[large] && !nonprime[large-2])  break;
        }

        cout << large-2 << " " << large << endl;
    }

    return 0;
}