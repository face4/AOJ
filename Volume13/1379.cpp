// 最初に自力で思いついた方法はまあまあ合ってた
// 計算量解析を間違っていて、その方法が現実的で無いと
// 思い込んでいた
// 1.8e8
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    return b==0 ? a : gcd(b, a%b);
}

typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    map<pii,vector<int>> m;
    pii p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int x = p[j].first-p[i].first;
            int y = p[j].second-p[i].second;
            int g = gcd(abs(x), abs(y));
            x /= g, y /= g;
            if(x < 0)   x *= -1, y *= -1;
            // {0, -1}, {0, 1}を同一視したい
            if(x == 0)  y = 1;
            m[{x,y}].push_back((1<<i)+(1<<j));
        }
    }
    vector<int> dp(1<<n, -1);
    dp[0] = 0;
    for(int s = 0; s < 1<<n; s++){
        if(dp[s] == -1) continue;
        for(auto p : m){
            int siz = p.second.size();
            for(int j = 0; j < 1<<siz; j++){
                int ors = 0, flag = 0, popcnt = 0;
                for(int k = 0; k < siz; k++){
                    if(j>>k&1){
                        ors |= p.second[k];
                        if(s&p.second[k])   flag = 1;
                        popcnt++;
                    }
                }
                if(flag==0) dp[s|ors] = max(dp[s|ors], dp[s]+popcnt*(popcnt-1)/2);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}