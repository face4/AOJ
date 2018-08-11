#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    int n, f;
    cin >> n >> f;

    map<string, map<string, int>> shop;
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;

        string x[m];
        for(int i = 0; i < m; i++)  cin >> x[i];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i == j)  continue;
                shop[x[i]][x[j]]++;
            }
        }
    }

    set<pair<string,string>> ans;

    for(auto x : shop){
        for(auto y : x.second){
            if(y.second >= f){
                string s = x.first;
                string t = y.first;
                if(s > t)   swap(s,t);
                ans.insert({s, t});
            }
        }
    }

    cout << ans.size() << endl;

    for(auto x : ans){
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}