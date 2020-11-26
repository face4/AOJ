#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int comb[1001][1001] = {};
const int mod = 1e6;
vector<int> v[1000];
int csum[1000] = {};
vector<ll> dp(1000, 1);

void f(int u){
    for(int child : v[u]){
        f(child);
        (dp[u] *= comb[csum[u]+csum[child]][csum[u]] * dp[child]) %= mod;
        csum[u] += csum[child];
    }
    csum[u]++;
}

int main(){
    comb[0][0] = 1;
    for(int i = 1; i <= 1000; i++){
        for(int j = 0; j <= i; j++){
            comb[i][j] += comb[i-1][j];
            if(j)   comb[i][j] += comb[i-1][j-1];
            comb[i][j] %= mod;
        }
    }
    int n;
    cin >> n;
    vector<bool> lose(n, 0);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        lose[b] = true;
    }
    for(int i = 0; i < n; i++){
        if(!lose[i]){
            f(i);
            cout << dp[i] << endl;
            return 0;
        }
    }
}