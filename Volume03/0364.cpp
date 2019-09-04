#include<iostream>
#include<set>
using namespace std;

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    set<pair<int,int>> x;
    multiset<int> y;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        x.insert({a, b});
        y.insert(b);
    }
    int ans = *y.rbegin();
    while(!x.empty()){
        int take = x.begin()->first;
        while(!x.empty() && x.begin()->first == take){
            y.erase(y.find(x.begin()->second));
            x.erase(x.begin());
        }
        ans = min(ans, (y.empty() ? 0 : *y.rbegin())+take);
    }
    cout << ans << endl;
    return 0;
}