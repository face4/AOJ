#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int enc(vector<int> a){
    int n = a.size();
    int ret = 0, th = 1;
    for(int i = 0; i < n; i++){
        ret += a[i] * th;
        th *= 3;
    }
    return ret;
}

vector<int> dec(int val, int n){
    vector<int> ret(n);
    for(int i = 0; i < n; i++){
        ret[i] = val%3;
        val /= 3;
    }
    return ret;
}

int pow(int a, int b){
    int ret = 1;
    while(b-- > 0)  ret *= a;
    return ret;
}

const int INF = 1<<30;

// 3^15 = 14348907 で十分間に合いそうだが、関数呼び出しが多いので危ないかもしれない
// どうやったら綺麗に書けるのかわからない

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        int ma = pow(3,n)-1;
        vector<int> dp(pow(3,n), INF);
        vector<int> a(n);
        for(int i = 0; i < 3; i++){
            int k;  cin >> k;
            while(k-- > 0){
                int x;  cin >> x;
                a[--x] = i;
            }
        }
        // state, step
        queue<int> q;
        q.push(enc(a));
        dp[enc(a)] = 0;
        int ans = m+1;
        while(!q.empty()){
            int p = q.front();  q.pop();
            if(dp[p] > m){
                break;
            }
            if(p == 0 || p == ma){
                ans = dp[p];
                break;
            }
            vector<int> v = dec(p, n);
            int big[3] = {-1,-1,-1};
            for(int i = 0; i < n; i++)  big[v[i]] = max(i, big[v[i]]);
            if(big[0] > big[1]){
                v[big[0]] = 1;
                int tmp = enc(v);
                if(dp[tmp] == INF){
                    dp[tmp] = dp[p]+1;
                    q.push(tmp);
                }
                v[big[0]] = 0;
            }
            if(big[1] > big[0]){
                v[big[1]] = 0;
                int tmp = enc(v);
                if(dp[tmp] == INF){
                    dp[tmp] = dp[p]+1;
                    q.push(tmp);
                }
                v[big[1]] = 1;
            }
            if(big[1] > big[2]){
                v[big[1]] = 2;
                int tmp = enc(v);
                if(dp[tmp] == INF){
                    dp[tmp] = dp[p]+1;
                    q.push(tmp);
                }
                v[big[1]] = 1;
            }
            if(big[2] > big[1]){
                v[big[2]] = 1;
                int tmp = enc(v);
                if(dp[tmp] == INF){
                    dp[tmp] = dp[p]+1;
                    q.push(tmp);
                }
                v[big[2]] = 2;
            }
        }
        cout << (ans > m ? -1 : ans) << endl;
    }
    return 0;
}