#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(n, 1<<30));
    for(int i = 0; i < n; i++)  v[i][i] = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a][b] = 1;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][k] == 1<<30 || v[k][j] == 1<<30)   continue;
                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }

    vector<int> ans[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] != 1<<30 && v[j][i] != 1<<30)    ans[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j]+1 << " \n"[j+1==ans[i].size()];
        }
    }
    
    return 0;
}
