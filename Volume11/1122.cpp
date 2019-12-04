#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<int>> sub;
    for(int i = 1; i < 1<<10; i++){
        vector<int> x;
        for(int j = 0; j < 10; j++) if((i>>j)&1)    x.push_back(j);
        sub.push_back(x);
    }

    int n, m;
    while(cin >> n >> m, n){
        vector<string> a(m);
        vector<int> b(m), c(m);
        for(int i = 0; i < m; i++)  cin >> a[i] >> b[i] >> c[i];
        vector<vector<bool>> origin(m, vector<bool>(10,0));
        for(int i = 0; i < m; i++){
            for(char c : a[i])  origin[i][c-'0'] = true;
        }
        bool no = false;
        vector<string> ans;
        for(vector<int> &x : sub){
            if(x.size() != n) continue;
            do{
                bool valid = true;
                for(int j = 0; valid && j < m; j++){
                    int blow = 0, hit = 0;
                    for(int k = 0; k < n; k++){
                        hit += a[j][k]-'0'==x[k];
                        blow += origin[j][x[k]];
                    }
                    blow -= hit;
                    valid &= b[j]==hit && c[j]==blow;
                }
                if(valid){
                    if(ans.size()){
                        no = true;
                        break;
                    }
                    string tmp = "";
                    for(int j = 0; j < n; j++)  tmp += (char)('0'+x[j]);
                    ans.push_back(tmp);
                }
            }while(next_permutation(x.begin(),x.end()));
            sort(x.begin(), x.end());
            if(no)  break;
        }
        if(ans.size() == 0 || no)  cout << "NO" << endl;
        else    cout << ans[0] << endl;

    }
    return 0;
}