#include<iostream>
#include<vector>
#include<functional>
using namespace std;

struct Area{
    int si, ti, sj, tj;
};

int main(){
    int w, h, n;
    while(cin >> w >> h >> n, w){
        int cnt[n+1];
        for(int i = 1; i <= n; i++){
            int a, b;
            cin >> a >> b;
            cnt[a] = b;
        }
        string s[h][w];
        for(int i = 0; i < h*w; i++)    cin >> s[i/w][i%w];
        vector<Area> ok[n+1];
        for(int si = 0; si < h; si++){
            for(int sj = 0; sj < w; sj++){
                for(int ti = si; ti < h; ti++){
                    for(int tj = sj; tj < w; tj++){
                        string tmp = "";
                        bool valid = true;
                        for(int i = si; i <= ti; i++){
                            for(int j = sj; j <= tj; j++){
                                if(s[i][j] == "0")  continue;
                                if(tmp != "" && tmp != s[i][j]){
                                    valid = false;
                                    break;
                                }
                                tmp = s[i][j];
                            }
                            if(!valid)  break;
                        }
                        if(tmp != "" && valid && (ti-si+1)*(tj-sj+1)==cnt[stoi(tmp)]){
                            ok[stoi(tmp)].push_back(Area({si,ti,sj,tj}));
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(h, vector<int>(w, 0)), pool(h, vector<int>(w, 0));
        bool na = false;
        function<void(int)> dfs = [&](int ind)->void{
            if(ind == n+1){
                if(pool[0][0] != 0){
                    na = true;
                    return;
                }
                pool = ans;
                return;
            }
            for(Area a : ok[ind]){
                bool valid = true;
                for(int i = a.si; i <= a.ti; i++){
                    for(int j = a.sj; j <= a.tj; j++){
                        valid &= ans[i][j] == 0;
                    }
                }
                if(!valid)  continue;
                for(int i = a.si; i <= a.ti; i++){
                    for(int j = a.sj; j <= a.tj; j++){
                        ans[i][j] = ind;
                    }
                }
                dfs(ind+1);
                for(int i = a.si; i <= a.ti; i++){
                    for(int j = a.sj; j <= a.tj; j++){
                        ans[i][j] = 0;
                    }
                }
            }
        };
        dfs(1);
        if(na || pool[0][0] == 0){
            cout << "NA" << endl;
        }else{
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    cout << pool[i][j] << " \n"[j==w-1];
                }
            }
        }
    }
    return 0;
}