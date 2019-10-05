#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

map<string,int> name;
vector<string> x[40];
vector<int> v[40];
vector<int> pow(40), res(41);
int n;
ll ans;

void dfs(int pos, ll bit, ll score){
    ans = max(ans, score);
    if(pos == n)    return;
    if(score + res[pos] <= ans)    return;
    ll tmp = 1ll<<pos;
    for(int x : v[pos])  tmp += 1ll<<x;
    if(((bit>>pos)&1) == 0)    dfs(pos+1, bit|tmp, score+pow[pos]);
    dfs(pos+1, bit, score);
}

int main(){
    while(cin >> n, n){
        name.clear();
        for(int i = 0; i < n; i++)  v[i].clear(), x[i].clear();
        for(int i = 0; i < n; i++){
            string s;
            int c;
            cin >> s >> pow[i] >> c;
            name[s] = i;
            while(c-- > 0){
                string t;   cin >> t;
                x[i].push_back(t);
            }
        }
        for(int i = 0; i < n; i++){
            for(string s : x[i])    v[i].push_back(name[s]);
        }
        ans = 0;
        res[n] = 0;
        for(int i = n-1; i >= 0; i--)   res[i] = res[i+1]+pow[i];
        ll start = 1;
        for(int x : v[0])    start += 1ll<<x;
        dfs(1, start, pow[0]);
        cout << ans << endl;
    }
    return 0;
}