#include<iostream>
#include<vector>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int n;
    cin >> n;

    int a[50][3][2];
    vector<int> v[3];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                int h, m;   cin >> h >> m;
                a[i][j][k] = 60*h+m;
                v[j].push_back(60*h+m);
            }
        }
    }

    int ans = 0;
    for(int x : v[0]){
        for(int y : v[1]){
            for(int z : v[2]){
                int tmp = 0;
                for(int k = 0; k < n; k++){
                    if(inRange(x, a[k][0][0], a[k][0][1]) && 
                       inRange(y, a[k][1][0], a[k][1][1]) &&
                       inRange(z, a[k][2][0], a[k][2][1])){
                           tmp++;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;

    return 0;
}