#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, u;
    while(cin >> n >> u, n+u){
        vector<int> c(n), p(n);
        for(int i = 0; i < n; i++){
            cin >> c[i];
            int k;  cin >> k;
            while(k-- > 0){
                int r;  cin >> r;
                p[i] |= (1<<r);
            }
        }
        
        auto popcnt = [](int x)->int{
            int ret = 0;
            while(x > 0){
                ret += x&1;
                x >>= 1;
            }
            return ret;
        };

        int ans = 21;
        queue<pair<int,int>> q;
        vector<bool> visit(1<<n, 0);
        q.push({0, 0});
        while(!q.empty()){
            pair<int,int> x = q.front();    q.pop();
            int bit = x.first, score = x.second;
            if(visit[bit])  continue;
            visit[bit] = true;
            if(score >= u){
                ans = min(ans, popcnt(bit));
                continue;
            }
            for(int i = 0; i < n; i++){
                if( ((bit>>i)&1) == 1 || (p[i]&bit) != p[i] || visit[bit|(1<<i)])    continue;
                q.push({bit|(1<<i), score+c[i]});
            }
        }
        cout << ans << endl;
    }
    return 0;
}