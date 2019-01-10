#include<iostream>
using namespace std;

const int mod = 1e9+7;

int main(){
    string t, b;
    cin >> t >> b;

    int dp[1001] = {};
    dp[0] = 1;

    for(int i = 0; i < t.length(); i++){
        for(int j = b.length()-1; j >= 0; j--){
            if(t[i] == b[j]){
                dp[j+1] = (dp[j+1]+dp[j])%mod;
            }
        }
    }

    cout << dp[b.length()] << endl;

    return 0;
}