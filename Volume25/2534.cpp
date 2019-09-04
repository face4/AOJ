#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int dp[26][26] = {};
        string b;
        cin >> b;
        bool ng = false;
        for(int i = 1; i < n; i++){
            string s;   cin >> s;
            int j;
            for(j = 0; j < min(b.length(), s.length()); j++){
                if(b[j] != s[j])    break;
            }
            if(j < min(b.length(), s.length())){
                dp[b[j]-'a'][s[j]-'a'] = -1;
            }else if(j == s.length() && j < b.length()){
                ng = true;
            }
            b = s;
        }
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dp[i][k] == 0 || dp[k][j] == 0)  continue;
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        for(int i = 0; i < 26; i++){
            ng |= (dp[i][i] < 0);
        }
        cout << (ng ? "no" : "yes") << endl;
    }
    return 0;
}