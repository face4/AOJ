#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n){
        int a[n], w[m];
        for(int i = 0; i < n; i++)  cin >> a[i];
        for(int i = 0; i < m; i++)  cin >> w[i];
        set<int> s;
        for(int i = 0; i < pow(3,m); i++){
            int x = 0, cp = i;
            for(int j = 0; j < m; j++)  x += (cp%3-1)*w[j], cp /= 3;
            s.insert(x);
        }
        vector<int> ng;
        for(int i = 0; i < n; i++)  if(s.count(a[i]) == 0)  ng.push_back(a[i]);
        if(ng.size() == 0){
            cout << 0 << endl;
            continue;
        }
        set<int> ok;
        for(int i : s){
            ok.insert(abs(i-ng[0]));
        }
        for(int i = 1; i < ng.size(); i++){
            set<int> nok;
            for(int x : ok) if(s.count(x+ng[i]) || s.count(abs(x-ng[i])))   nok.insert(x);
            ok = nok;
        }
        cout << (ok.empty() ? -1 : *ok.begin()) << endl;
    }
    return 0;
}