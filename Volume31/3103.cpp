#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<pair<int,ll>> v[100000];
vector<bool> visit(100000, 0);

int n, t, s, e;
bool ok = true;

void dfs(int pos){
    visit[pos] = true;
    for(int i = 0; i < v[pos].size(); i++){
        v[pos][i].second -= t;
        if(v[pos][i].second <= 0){
            if(!visit[v[pos][i].first]){
                ok = false;
            }else{
                continue;
            }
        }
        if(v[pos][i].first == e)    continue; // add
        if(visit[v[pos][i].first])  continue;
        dfs(v[pos][i].first);
        v[pos][i].second -= t;
    }
}

int main(){
    cin >> n >> t >> s >> e;
    s--, e--;
    for(int i = 0; i < n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }

    dfs(s);
    dfs(e);

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
