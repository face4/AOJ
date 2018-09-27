#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int a[2][n];
        for(int i = 0; i < n; i++)  cin >> a[0][i];
        for(int i = 0; i < n; i++)  cin >> a[1][i];
        bool va[2][n];
        memset(va, 0, sizeof(va));

        // {{building, floor}, step}
        queue<pair<pair<int,int>,int>> s;
        s.push({{0,0},0});
        s.push({{1,0},0});

        int ans = -1;
        while(!s.empty()){
            auto p = s.front(); s.pop();
            int b = p.first.first, f = p.first.second, h = p.second;
            while(a[b][f] == 2) f--;
            while(f+1 < n && a[b][f] == 1 && a[b][f+1] == 1)  f++;
            
            if(f == n-1){
                ans = h;
                break;
            }

            if(va[b][f])    continue;
            
            va[b][f] = true;

            b ^= 1;
            for(int i = 0; i < 3; i++){
                if(f+i >= n)    break;
                if(!va[b][f+i]) s.push({{b, f+i}, h+1});
            }

        }

        if(ans == -1)   cout << "NA" << endl;
        else            cout << ans << endl;
    }
    
    return 0;
}