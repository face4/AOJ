#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int mod = 1000000007;

ll dp[1000] = {};
vector<int> v[1000];
string s[1000];
int n;

int dfs(int x){
    dp[x] = s[x][0]!='A';
    for(int child : v[x]){
        if(s[x][0] == 'A')  dp[x] += dfs(child);
        else                (dp[x] *= dfs(child)+(s[x][0]=='R')) %= mod;
    }
    if(s[x] == "E?")    dp[x] = (dp[x]+1)%mod;
    if(s[x] == "R")     dp[x] = (dp[x]-1+mod)%mod;
    if(s[x] == "A?")    dp[x] = (dp[x]+1)%mod;
    return dp[x];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> s[i];
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
    }
    cout << dfs(0) << endl;
    return 0;
}