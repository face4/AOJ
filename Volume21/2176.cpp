#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, d;
    while(cin >> n >> d, n+d){
        vector<int> sum(n, 0), v[n], ind(n, 0);
        for(int i = 0; i < n; i++){
            int m;  cin >> m;
            while(m-- > 0){
                int x;  cin >> x;
                v[i].push_back(x);
                sum[i] += x;
            }
            reverse(v[i].begin(), v[i].end());
        }
        bool update = true;
        while(update){
            update = false;
            for(int i = 0; i < n; i++){
                if(sum[i] == 0) continue;
                int ma = 0, mi = 1<<30;
                for(int j = 0; j < n; j++){
                    if(i == j)  ma=max(ma,sum[i]-v[i][ind[i]]), mi=min(mi,sum[i]-v[i][ind[i]]);
                    else        ma=max(ma,sum[j]), mi=min(mi,sum[j]);
                }
                if(ma-mi <= d){
                    update = true;
                    sum[i] -= v[i][ind[i]++];
                    break;
                }
            }
        }
        cout << (*max_element(sum.begin(),sum.end()) == 0 ? "Yes" : "No") << endl;
    }
    return 0;
}