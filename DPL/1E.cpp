#include<iostream>
using namespace std;

int LevenDis(string a, string b){
    int alen = a.length(), blen = b.length();
    int dp[alen+1][blen+1];

    for(int i = 0; i < alen+1; i++) dp[i][0] = i;
    for(int j = 0; j < blen+1; j++) dp[0][j] = j;

    for(int i = 1; i < alen+1; i++){
        for(int j = 1; j < blen+1; j++){
            dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+(a[i-1] != b[j-1])));
        }
    }

    return dp[alen][blen];
}

int main(){
    string x, y;
    cin >> x >> y;
    cout << LevenDis(x,y) << endl;
    return 0;
}