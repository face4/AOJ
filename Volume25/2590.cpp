#include<iostream>
#include<vector>
using namespace std;

// ???
int main(){
    auto f = [](int val)->char{
        if(val <= 9)    return (char)('0'+val);
        return (char)('A'+val-10);
    };

    int n, m, q;
    while(cin >> n >> m >> q, n+m+q){
        vector<string> s(q+1), b(q+1);
        s[0] = b[0] = "";
        for(int i = 0; i < n; i++)  s[0] += "0";
        for(int i = 0; i < m; i++)  b[0] += "0";
        for(int i = 1; i <= q; i++)  cin >> s[i] >> b[i];
        vector<int> cnt(m, 0);
        vector<bool> push(n, 0);
        vector<vector<int>> tmp(n, vector<int>(m, 0));
        vector<vector<bool>> flag(n, vector<bool>(m,0));
        for(int i = 1; i <= q; i++){
            for(int j = 0; j < m; j++){
                if(b[i-1][j] != b[i][j])    cnt[j]++;
                for(int k = 0; k < n; k++){
                    if(s[i][k] == '1'){
                        push[k] = true;
                        tmp[k][j] += b[i-1][j] != b[i][j];
                        if(b[i-1][j]==b[i][j])  flag[k][j] = true;
                    }
                }
            }
        }
        int notpushed = 0, ind = -1;
        for(int i = 0; i < n; i++)  if(!push[i]) notpushed++, ind = i;
        for(int i = 0; i < m; i++){
            if(cnt[i] == 0){
                cout << (notpushed==1 ? f(ind) : '?');
            }else{
                int tmpcnt = 0, ind = -1;
                for(int j = 0; j < n; j++){
                    if(!flag[j][i] && cnt[i] == tmp[j][i]){
                        tmpcnt++, ind = j;
                    }
                }
                cout << (tmpcnt==1 ? f(ind) : '?');
            }
        }
        cout << endl;
    }
    return 0;
}