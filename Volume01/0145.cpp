#include<iostream>
#include<climits>
using namespace std;

int dp[100][100] = {}, a[100], b[100], n;
bool visit[100][100] = {};

int dfs(int s, int t){
    if(visit[s][t]) return dp[s][t];
    visit[s][t] = true;
    if(s == t)  return dp[s][t] = 0;
    if(s+1 == t){
        return dp[s][t] = a[s]*a[t]*b[s]*b[t];
    }
    int score = INT_MAX;
    for(int j = s; j < t; j++){
        score = min(score, a[s]*b[j]*a[j+1]*b[t]+dfs(s,j)+dfs(j+1,t));
    }
    return dp[s][t] = score;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];

    cout << dfs(0, n-1) << endl;

    return 0;
}