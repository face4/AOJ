#include<iostream>
#include<stack>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll h[n];
    for(int i = 0; i < n; i++)  cin >> h[i];

    stack<pair<int,ll>> s;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.push({i, h[i]});
        }else if(s.top().second > h[i]){
            pair<int,ll> tmp;
            while(!s.empty()){
                if(s.top().second <= h[i])  break;
                tmp = s.top();
                ans = max(ans, (i-tmp.first)*tmp.second );
                s.pop();
            }
            s.push({tmp.first, h[i]});
        }else if(s.top().second < h[i]){
            s.push({i, h[i]});
        }
    }

    while(!s.empty()){
        auto x = s.top(); s.pop();
        ans = max(ans, (n-x.first)*x.second);
    }

    cout << ans << endl;

    return 0;
}