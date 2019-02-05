#include<iostream>
#include<set>
#include<cstring>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int toi[n][n], toj[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> toj[i][j] >> toi[i][j];
            }
        }
        bool visit[n][n];
        memset(visit, 0, sizeof(visit));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visit[i][j]) continue;
                set<pair<int,int>> used;
                int ni = i, nj = j;
                while(!visit[ni][nj]){
                    used.insert({ni,nj});
                    visit[ni][nj] = true;
                    int nni = toi[ni][nj], nnj = toj[ni][nj];
                    ni = nni, nj = nnj;
                }
                if(used.count({ni,nj})) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}