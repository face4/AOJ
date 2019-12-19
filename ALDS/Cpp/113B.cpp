#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(){
    map<string,int> dp;
    string g = "123456780";
    string t = "";
    for(int i = 0; i < 9; i++){
        char c; cin >> c;
        t += c;
    }
    dp[t] = 0;
    queue<string> q;
    q.push(t);
    while(!q.empty()){
        string s = q.front();   q.pop();
        int now = dp[s];
        if(s == g){
            cout << dp[s] << endl;
            return 0;
        }
        for(int i = 0; i < 9; i++){
            if(i%3==2)  continue;
            if(s[i] != '0' && s[i+1] != '0')    continue;
            swap(s[i], s[i+1]);
            if(dp.count(s) == 0){
                dp[s] = now+1;
                q.push(s);
            }
            swap(s[i], s[i+1]);
        }
        for(int i = 0; i < 6; i++){
            if(s[i] != '0' && s[i+3] != '0')    continue;
            swap(s[i], s[i+3]);
            if(dp.count(s) == 0){
                dp[s] = now+1;
                q.push(s);
            }
            swap(s[i], s[i+3]);   
        }
    }
}
