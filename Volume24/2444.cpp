#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const ull B = 1000000007;

int main(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<ull> v(n+1);
    v[0] = 0;
    for(int i = 0; i < n; i++){
        v[i+1] = v[i]*B + s[i];
    }
    vector<ull> f(n+1);
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = f[i-1]*B;
    int a = 1, b = 1;
    vector<ull> ans;
    while(m--){
        string s;
        cin >> s;
        if(s == "L++")  a++;
        if(s == "R++")  b++;
        if(s == "L--")  a--;
        if(s == "R--")  b--;
        ans.push_back(v[b]-v[a-1]*f[b-a+1]);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout << ans.size() << endl;
    return 0;
}