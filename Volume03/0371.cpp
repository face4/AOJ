#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    int ma = 0;
    for(int i = 0; i < n; i++)  cin >> t[i], ma = max(ma, t[i]);
    vector<int> p;
    for(int i = 1; i <= ma; i++){
        if(ma%i == 0)    p.push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += *(lower_bound(p.begin(), p.end(), t[i]))-t[i];
    }
    cout << ans << endl;
    return 0;
}
