#include<iostream>
#include<set>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n;
    cin >> n;
    set<int> s[n*n+1];
    for(int i = 0; i < 2*n*n-2*n; i++){
        int a, b;
        cin >> a >> b;
        s[a].insert(b);
        s[b].insert(a);
    }
    int ans[n][n], next;
    for(int i = 1; i <= n*n; i++){
        if(s[i].size() != 2)    continue;
        ans[0][0] = i;
        for(int j : s[i]){
            s[j].erase(i);
            next = j;
        }
        ans[0][1] = next;
        int tmp = -1, mi = 4;
        for(int j : s[next]){
            s[j].erase(next);
            if(inRange(s[j].size(), 0, mi)){
                tmp = j;
                mi = s[tmp].size();
            }
        }
        next = tmp;
        break;
    }
    set<int> done; // ugly!
    done.insert(ans[0][0]);
    done.insert(ans[0][1]);
    for(int i = 0; i < n; i++){
        if(i){
            // ugly!
            for(int j : s[ans[i-1][0]])   if(done.count(j) == 0)  next = j;
        }
        for(int j = (i==0 ? 2 : 0); j < n; j++){
            ans[i][j] = next;
            done.insert(next);
            int tmp = -1, mi = 4;
            for(int k : s[next]){
                s[k].erase(next);
                if((i==0 || j==n-1 || s[ans[i-1][j+1]].count(k)) && inRange(s[k].size(), 0, mi)){
                    tmp = k;
                    mi = s[tmp].size();
                }
            }
            next = tmp;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " \n"[j==n-1];
        }
    }
    return 0;
}