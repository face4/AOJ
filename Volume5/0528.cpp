#include<iostream>
using namespace std;

int getLCSlen(string a, string b){
    int dp[a.length()][b.length()];
    int ret = 0;

    for(int i = 0; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++){
            dp[i][j] = 0;
        }
    }

    for(int j = 0; j < b.length(); j++) if(a[0] == b[j])    dp[0][j] = 1;
    for(int i = 0; i < a.length(); i++) if(a[i] == b[0])    dp[i][0] = 1;

    for(int i = 1; i < a.length(); i++){
        for(int j = 1; j < b.length(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                ret = max(ret, dp[i][j]);
            }
            // add these if you want to get longest common subsequence
            // dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            // ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

int main(){
    string a, b;
    while(cin >> a >> b){
        cout << getLCSlen(a, b) << endl;
    }
}