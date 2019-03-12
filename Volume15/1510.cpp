#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n, caseNum = 1;
    while(cin >> n, n){
        vector<vector<vector<int>>> v(5, vector<vector<int>>(5, vector<int>(5)));
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    char c; cin >> c;
                    v[i][j][k] = c-'0';
                }
            }
        }
        set<int> death, alive;
        int k, x;
        cin >> k;
        while(k-- > 0)  cin >> x, death.insert(x);
        cin >> k;
        while(k-- > 0)  cin >> x, alive.insert(x);

        for(int i = 0; i < n; i++){
            vector<vector<vector<int>>> next(5, vector<vector<int>>(5, vector<int>(5)));
            vector<vector<vector<int>>> around(5, vector<vector<int>>(5, vector<int>(5, 0)));
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    for(int l = 0; l < 5; l++){
                        if(v[j][k][l] == 0) continue;
                        for(int dj = -1; dj <= 1; dj++){
                            for(int dk = -1; dk <= 1; dk++){
                                for(int dl = -1; dl <= 1; dl++){
                                    if(dj==0 && dk==0 && dl==0) continue;
                                    if(inRange(j+dj,0,5)&&inRange(k+dk,0,5)&&inRange(l+dl,0,5)){
                                        around[j+dj][k+dk][l+dl]++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    for(int l = 0; l < 5; l++){
                        if(v[j][k][l]){
                            next[j][k][l] = alive.count(around[j][k][l]);
                        }else{
                            next[j][k][l] = death.count(around[j][k][l]);
                        }
                    }
                }
            }
            v = next;
        }

        if(caseNum-1)   cout << endl;
        cout << "Case " << caseNum++ << ":" << endl;
        for(int i= 0; i < 5; i++){
            if(i)   cout << endl;
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    cout << v[i][j][k];
                }
                cout << endl;
            }
        }

    }
    return 0;
}