#include<iostream>
#include<vector>
#include<cfloat>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    int n, m, p, a, b;
    while(cin >> n >> m >> p >> a >> b, n+m+p+a+b){
        a--, b--;
        vector<int> t(n);
        for(int i = 0; i < n; i++)  cin >> t[i];
        vector<pair<int,int>> v[m];
        int x, y, z;
        for(int i = 0; i < p; i++){
            cin >> x >> y >> z;
            x--, y--;
            v[x].push_back({y,z});
            v[y].push_back({x,z});
        }
        vector<vector<double>> d(1<<n, vector<double>(m, DBL_MAX));
        // dist, pos, bit
        priority_queue<pair<double, pair<int, int>>> q;
        q.push({-0, {a, 0}});
        double res = DBL_MAX;
        while(!q.empty()){
            auto p = q.top(); q.pop();
            double cost = -p.first;
            int pos = p.second.first, bit = p.second.second;
            if(d[bit][pos] <= cost) continue;
            d[bit][pos] = cost;
            if(pos == b){
                res = cost;
                break;
            }
            for(pair<int,int> next : v[pos]){
                int tmp = next.first;
                double tmpd = next.second;
                for(int j = 0; j < n; j++){
                    if((bit>>j) & 1)    continue;
                    if(d[bit|(1<<j)][tmp] > cost + tmpd/t[j]){
                        q.push({-(cost+tmpd/t[j]), {tmp, bit|(1<<j)}});
                    }
                }
            }
        }
        if(res == DBL_MAX)  cout << "Impossible" << endl;
        else                cout << fixed << setprecision(12) << res << endl;
    }
    return 0;
}