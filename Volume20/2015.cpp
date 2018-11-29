#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        int h[n+1], w[m+1];
        h[0] = w[0] = 0;
        for(int i = 1; i <= n; i++) cin >> h[i], h[i] += h[i-1];
        for(int j = 1; j <= m; j++) cin >> w[j], w[j] += w[j-1];

        map<int,int> height, width;
        
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                height[h[j]-h[i-1]]++;
            }
        }

        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                width[w[j]-w[i-1]]++;
            }
        }

        ll ans = 0;
        for(pair<int,int> p : height){
            if(width.count(p.first))    ans += (ll)(p.second) * width[p.first];
        }
        cout << ans << endl;
    }
    return 0;
}