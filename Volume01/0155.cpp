#include<iostream>
#include<vector>
#include<queue>
#include<cfloat>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<int> b(n), x(n), y(n);
        for(int i = 0; i < n; i++)  cin >> b[i] >> x[i] >> y[i];
        int m;
        cin >> m;
        while(m-- > 0){
            int s, g;
            cin >> s >> g;
            vector<double> dp(n, DBL_MAX);
            vector<int> back(n, -1);
            priority_queue<pair<double, pair<int, int>>> pq;
            int sind, gind;
            for(int i = 0; i < n; i++){
                if(b[i] == s)   sind = i;
                if(b[i] == g)   gind = i;
            }
            pq.push({-0, {sind, -1}});
            while(!pq.empty()){
                auto p = pq.top();  pq.pop();
                double cost = -p.first;
                int pos = p.second.first, par = p.second.second;
                if(dp[pos] <= cost) continue;
                dp[pos] = cost;
                back[pos] = par;
                if(pos == gind) break;
                for(int j = 0; j < n; j++){
                    double dist = sqrt(pow(x[j]-x[pos], 2.0)+pow(y[j]-y[pos], 2.0));
                    if(dist > 50.0) continue;
                    if(dp[j] > cost + dist){
                        pq.push({-(cost+dist), {j, pos}});
                    }
                }
            }
            if(dp[gind] == DBL_MAX){
                cout << "NA" << endl;
                continue;
            }
            vector<int> ans;
            while(gind != -1){
                ans.push_back(b[gind]);
                gind = back[gind];
            }
            reverse(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " \n"[i+1==ans.size()];
            }
        }
    }
    return 0;
}