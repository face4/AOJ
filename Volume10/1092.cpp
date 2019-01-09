#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int s, d, m, k, w, p, f;

    while(cin >> s >> d >> m){
        int dp[301] = {};

        vector<pair<int,int>> v[s];
        for(int i = 0; i < s; i++){
            cin >> k;
            while(k-- > 0){
                cin >> w >> p;
                v[i].push_back({w,p});
            }
        }

        map<pair<int,int>,int> ma;

        for(int i = 0; i < d; i++){
            cin >> f;
            for(pair<int,int> price : v[f]) ma[price]++;
        }

        for(auto x : ma){
            pair<int,int> price = x.first;
            for(int i = 0; i < ma[price]; i++){
                // 2進を使って効率よくやった方が良いかもしれないが、面倒なのでさぼる
                for(int j = m; j >= price.second; j--){
                    dp[j] = max(dp[j], dp[j-price.second]+price.first);
                }
            }
        }

        int a = 0, b = 0;
        for(int i = 0; i <= m; i++){
            if(dp[i] > a){
                a = dp[i], b = i;
            }
        }
        cout << a << " " << b << endl;
    }

    return 0;
}