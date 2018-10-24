#include<iostream>
#include<vector>
using namespace std;

int main(){
    bool nonprime[10001] = {};
    nonprime[0] = nonprime[1] = true;
    int sum[10001] = {}, pos = 0;
    for(int i = 2; i < 10001; i++){
        if(nonprime[i]) continue;
        sum[pos+1] = sum[pos] + i;
        pos++;
        for(int j = i+i; j < 10001; j+=i)   nonprime[j] = true;
    }

    int ans[10001] = {};
    for(int i = 0; i < pos; i++){
        for(int j = i; j < pos; j++){
            if(sum[j]-sum[i] > 10000)   break;
            ans[sum[j]-sum[i]]++;
        }
    }

    int n;
    while(cin >> n, n)  cout << ans[n] << endl;
    
    return 0;
}