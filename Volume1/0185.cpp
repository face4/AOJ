#include<iostream>
#include<vector>
using namespace std;

int main(){
    bool nonPrime[1000001] = {};
    nonPrime[0] = nonPrime[1] = true;
    vector<int> prime;
    
    for(int i = 2; i <= 1000000; i++){
        if(!nonPrime[i]){
            prime.push_back(i);
            for(int j = i+i; j <= 1000000; j+=i){
                nonPrime[j] = true;
            }
        }
    }

    //for(int p : prime)  cout << p << endl;

    int n;
    while(1){
        cin >> n;
        if(n == 0)  break;

        int ans = 0;
        for(int p : prime){
            if(p > n)   break;
            if(!nonPrime[n-p])  ans++;
        }
        
        cout << (ans+1) /2<< endl;
    }

    return 0;
}