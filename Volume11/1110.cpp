#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
#define inRange(x,a,b) (a <= x && x < b)

ll enc(vector<int> v){
    ll ret = 0;
    for(int i = 0; i < v.size(); i++)   ret = ret * 5 + v[i];
    return ret;
}

map<ll, int> memo;
int ans;

int dfs(vector<int> v){
    ll num = enc(v);
    if(memo.count(num)) return memo[num];
    memo[num] = v.size();
    
    vector<vector<int>> mat(5, vector<int>(4, 0));
    for(int i = 0; i < v.size(); i++){
        mat[i/4][i%4] = v[i];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            if(mat[i][j] == 0)  break;
            for(int k = 0; k < 8; k++){
                int ni = i + di[k], nj = j + dj[k];
                if(!inRange(ni,0,5) || !inRange(nj, 0,4) || mat[ni][nj] != mat[i][j])   continue;
                int cp = mat[i][j];
                mat[ni][nj] = mat[i][j] = 0;
                vector<int> vcp;
                for(int l = 0; l < 5; l++){
                    for(int m = 0; m < 4; m++){
                        if(mat[l][m])   vcp.push_back(mat[l][m]);
                    }
                }
                memo[num] = min(memo[num], dfs(vcp));
                mat[ni][nj] = mat[i][j] = cp;
            }
        }
    }
    
    ans = min(ans, memo[num]);

    return memo[num];
}

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        memo.clear();   ans = 20;
        vector<int> v(20);
        for(int i = 0; i < 20; i++) cin >> v[i];
        dfs(v);
        cout << ans << endl;
    }
    return 0;
}