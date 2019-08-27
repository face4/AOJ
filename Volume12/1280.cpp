#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct UF{
    vector<int> p;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int parent(int x){
        if(p[x] != x)   p[x] = parent(p[x]);
        return p[x];
    }

    bool same(int i, int j){
        return parent(i) == parent(j);
    }

    void unite(int x, int y){
        x = parent(x), y = parent(y);
        p[x] = y;
    }
};

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        priority_queue<pair<int,pair<int,int>>> pq;
        int a, b, w;
        while(m-- > 0){
            cin >> a >> b >> w;
            pq.push({-w, {--a, --b}});
        }
        int cnt = 0;
        UF uf(n);
        auto c = pq;
        while(!c.empty()){
            auto p = c.top();   c.pop();
            int i = p.second.first, j = p.second.second;
            if(!uf.same(i, j)){
                cnt++;
                uf.unite(i, j);
            }
        }
        if(cnt != n-1){
            cout << -1 << endl;
            continue;
        }
        int ans = 1<<30;
        int bef = 0;
        while(true){
            while(pq.size() > 0 && pq.top().first == bef)   pq.pop();
            if(pq.size() == 0)  break;
            bef = pq.top().first;
            cnt = 0;
            UF u(n);
            auto c = pq;
            int aft = bef;
            while(!c.empty() && cnt < n-1){
                auto p = c.top();   c.pop();
                int i = p.second.first, j = p.second.second;
                if(!u.same(i,j)){
                    aft = p.first;
                    u.unite(i, j);
                    cnt++;
                }
            }
            if(cnt < n-1){
                break;
            }
            ans = min(ans, bef-aft);
        }
        cout << ans << endl;
    }
    return 0;
}