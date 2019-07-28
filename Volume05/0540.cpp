#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n, m, h, k;
    while(scanf("%d %d %d %d", &n, &m, &h, &k), n){
        vector<int> p(n);
        for(int i = 0; i < n; i++)  scanf("%d", p.begin()+i);

        vector<int> bar[1000];
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            bar[b].push_back(a);
        }

        for(int i = h-1; i >= 1; i--){
            for(int j : bar[i]) swap(p[j-1], p[j]);
        }

        vector<int> pos(n, -1);
        for(int i = 0; i < k; i++)  pos[i] = i;

        int ans = 0;
        for(int i = 0; i < n; i++) if(pos[i] != -1) ans += p[i];
        
        for(int i = 1; i <= h-1; i++){
            for(int j : bar[i]){
                swap(p[j-1], p[j]);
                int tmp = 0;
                for(int x = 0; x < n; x++){
                    if(pos[x] != -1)    tmp += p[x];
                }
                ans = min(ans, tmp);
                swap(p[j-1], p[j]);
            }
            for(int j : bar[i]){
                swap(p[j-1], p[j]);
                swap(pos[j-1], pos[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}