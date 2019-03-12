#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n, a, b;
    multiset<int> m;
    vector<int> v[32];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }
    int ans = 0;
    for(int i = 1; i <= 31; i++){
        for(int x : v[i])   m.insert(x);
        while(!m.empty() && *(m.begin()) < i)  m.erase(m.begin());
        if(m.empty())   ans++;
        else            ans += 2, m.erase(m.begin());
    }
    cout << ans*50 << endl;
    return 0;
}