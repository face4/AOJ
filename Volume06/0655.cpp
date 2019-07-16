#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> sink(n+2, 0);
    sink[0] = sink[n+1] = true; // centinel
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        vp.push_back({x, i+1});
    }
    vp.push_back({0, 0});  // centinel
    sort(vp.begin(), vp.end());
    int ans = 0, tmp = 1;
    for(int i = 1; i < vp.size(); i++){
        if(vp[i].first != vp[i-1].first)    ans = max(ans, tmp);
        int pos = vp[i].second;
        sink[pos] = true;
        if(sink[pos-1]+sink[pos+1] == 0)        tmp++;
        else if(sink[pos-1]+sink[pos+1] == 2)   tmp--;
    }
    cout << max(ans, tmp) << endl;
    return 0;
}