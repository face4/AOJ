#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

struct LCA{
    int n, bit; // n < 1<<bit
    vector<int> depth;
    vector<vector<int>> par, v;

    LCA(int n) : n(n){
        depth.resize(n, -1);
        bit = 0;
        while(1<<bit <= n)  bit++;
        par.resize(bit);
        for(int i = 0; i < bit; i++)    par[i].resize(n);
        v.resize(n);
    }

    void add_edge(int a, int b){
        v[a].push_back(b);
        v[b].push_back(a);
    }

    void dfs(int now, int p, int d){
        par[0][now] = p;
        depth[now] = d;
        for(int child : v[now]){
            if(child == p)  continue;
            dfs(child, now, d+1);
        }
    }

    void build(){
        for(int i = 0; i < n; i++){
            if(depth[i] == -1)    dfs(i, -1, 0);
        }
        for(int k = 0; k+1 < bit; k++){
            for(int i = 0; i < n; i++){
                if(par[k][i] < 0)   par[k+1][i] = -1;
                else                par[k+1][i] = par[k][par[k][i]];
            }
        }
    }

    int lca(int a, int b){
        // make b deeper
        if(depth[a] > depth[b]) swap(a, b);
        for(int k = 0; k < 30; k++){
            // depth(b)-depth(a) is equal to or bigger than 2^k
            if(((depth[b]-depth[a])>>k)&1){
                b = par[k][b];
            }
        }
        if(a == b)  return a;
        for(int k = bit-1; k >= 0; k--){
            if(par[k][a] != par[k][b]){
                a = par[k][a];
                b = par[k][b];
            }
        }
        return par[0][a];
    }

    int dist(int a, int b){
        int l = lca(a, b);
        return depth[a]-depth[l] + depth[b]-depth[l];
    }
};

int main(){
    int n, m;
    while(scanf("%d %d\n", &n, &m), n+m){
        vector<string> name(n);
        vector<int> depth(n);
        map<string,int> id;
        LCA l(n);
        stack<pair<int,int>> his;
        for(int i = 0; i < n; i++){
            string s;
            getline(cin, s);
            int dep;
            for(dep = 0; s[dep]==' '; dep++);
            name[i] = s.substr(dep);
            id[name[i]] = i;
            depth[i] = dep;
            while(!his.empty()&&his.top().second+1!=dep)    his.pop();
            if(!his.empty())    l.add_edge(i, his.top().first);
            his.push({i, dep});
        }
        l.build();
        while(m--){
            string a, b, c;
            cin >> a >> b >> b >> b >> c >> c;
            c.pop_back();
            int x = id[a], y = id[c];
            bool judge =    (b=="child" && l.lca(x,y)==y && depth[y]+1==depth[x]) || 
                            (b=="parent" && l.lca(x,y)==x && depth[x]+1==depth[y]) ||
                            (b=="sibling" && depth[x]==depth[y] && depth[x]==depth[l.lca(x,y)]+1) ||
                            (b=="ancestor" && l.lca(x,y)==x) || 
                            (b=="descendant" && l.lca(x,y)==y);
            cout << (judge ? "True" : "False") << endl;
        }
        cout << endl;
        cin.ignore(0);
    }
    return 0;
}