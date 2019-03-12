#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        string s[n];
        vector<int> app[n], cnt(30, n+1);
        for(int i = 0; i < n; i++){
            cin >> s[i];
            int k;  cin >> k;
            while(k-- > 0){
                int x;  cin >> x;
                app[i].push_back(x);
                cnt[x]--;
            }
        }
        vector<pair<int,string>> ans;
        for(int i = 0; i < n; i++){
            int tmp = 0;
            for(int k : app[i]){
                tmp += cnt[k];
            }
            ans.push_back({tmp, s[i]});
        }
        sort(ans.begin(), ans.end());
        cout << ans[0].first << " " << ans[0].second << endl;
    }
    return 0;
}