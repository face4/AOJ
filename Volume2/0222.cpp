#include<iostream>
#include<vector>
using namespace std;

bool nonprime[10000001] = {};

int main(){
    vector<int> prime;
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i < 10000001; i++){
        if(!nonprime[i]){
            prime.push_back(i);
            for(int j = i+i; j < 10000001; j+=i)
                nonprime[j] = true;
        }
    }

    vector<int> quad;
    for(int i = 0; i <= prime.size()-4; i++){
        if(prime[i]+2 == prime[i+1] && prime[i]+6 == prime[i+2] && prime[i]+8 == prime[i+3]){
            quad.push_back(prime[i+3]);
        }
    }

    int n;
    while(cin >> n, n){
        vector<int>::iterator it = lower_bound(quad.begin(), quad.end(), n);
        if(*it == n){
            cout << n << endl;
        }else{
            it--;
            cout << *it << endl;
        }
    }

    return 0;
}