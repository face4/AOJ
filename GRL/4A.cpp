#include<iostream>
#include<vector>
using namespace std;

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> d(v, vector<int>(v, 0));
    int s , t;
    while(e-- > 0){
        cin >> s >> t;
        d[s][t] = -1;
    }
    for(int k = 0; k < v; k++){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(d[i][k] == 0 || d[k][j] == 0)    continue;
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    bool nocycle = true;
    for(int i = 0; i < v; i++)  nocycle &= (d[i][i] == 0);
    cout << (nocycle ? 0 : 1) << endl;
    return 0;
}