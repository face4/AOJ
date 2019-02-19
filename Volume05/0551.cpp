#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[100002] = {};
ll dp[100001] = {};
int l;

ll dfs(int i){
    if(dp[i] != 0)  return dp[i];
    ll ret = l-a[i];
    if(a[i] < a[i-1] && a[i] < a[i+1]){
        ret += max(dfs(i-1), dfs(i+1));
    }else if(a[i] < a[i-1]){
        ret += dfs(i-1);
    }else if(a[i] < a[i+1]){
        ret += dfs(i+1);
    }
    return dp[i] = ret;
}

int main(){
    int n;
    cin >> n >> l;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) dfs(i);

    cout << *max_element(dp+1, dp+n+1) << endl;

    return 0;
}