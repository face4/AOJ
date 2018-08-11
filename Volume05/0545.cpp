#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    while(1){
        int n, m;
        cin >> n >> m;

        if(n + m == 0)  break;

        vector<int> p[n+1];
        int x, y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            p[x].push_back(y);
            p[y].push_back(x);
        }

        set<int> bef, after;
        for(int i = 0; i < p[1].size(); i++){
            bef.insert(p[1][i]);
        }
        for(int x : bef){
            for(int i = 0; i < p[x].size(); i++){
                after.insert(p[x][i]);
            }
        }
        for(int x : bef)    after.insert(x);
        after.insert(1);
        
        cout << after.size()-1 << endl;
    }
    return 0;
}