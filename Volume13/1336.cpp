#include<iostream>
#include<vector>
using namespace std;

// 愚直なシミュレート
int main(){
    int n, l;
    while(cin >> n >> l, n+l){
        vector<vector<int>> v(2, vector<int>(l+1, 0));
        for(int i = 0; i < n; i++){
            char c; int p;
            cin >> c >> p;
            if(c == 'L')    v[0][p] = i+1;
            else            v[1][p] = i+1;
        }
        int tim = -1, exit = 0, id = -1;
        while(exit < n){
            tim++;
            for(int j = l; j >= 0; j--){
                if(v[1][j] == 0)    continue;
                if(j == l){
                    exit++, id = v[1][j];
                    v[1][j] = 0;
                }else{
                    swap(v[1][j], v[1][j+1]);
                }
            }
            for(int j = 0; j <= l; j++){
                if(v[0][j] == 0)    continue;
                if(j == 0){
                    exit++, id = v[0][j];
                    v[0][j] = 0;
                }else{
                    swap(v[0][j-1], v[0][j]);
                }
            }
            for(int j = 0; j <= l; j++){
                if(v[0][j] != 0 && v[1][j] != 0){
                    swap(v[0][j], v[1][j]);
                }
            }
        }
        cout << tim << " " << id << endl;
    }
    return 0;
}