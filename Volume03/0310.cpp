// そすうささんのブログを読んだ
#include<iostream>
using namespace std;

int a[302][302], yoko[302][302] = {}, tate[302][302] = {};

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            yoko[i][j] = a[i][j]+yoko[i][j-1];
            tate[i][j] = a[i][j]+tate[i-1][j];
        }
    }
    int ans = -1000;
    // line
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            for(int k = 1; k <= n; k++){
                ans = max(ans, yoko[k][j]-yoko[k][i-1]);
                ans = max(ans, tate[j][k]-tate[i-1][k]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int all = yoko[i][n]+yoko[j][n];
            int submax = (tate[j-1][1]-tate[i][1]) - yoko[j][0] - yoko[i][0];
            for(int k = 2; k <= n; k++){
                int right = tate[j-1][k]-tate[i][k] - (yoko[j][n]-yoko[j][k]) - (yoko[i][n]-yoko[i][k]);
                ans = max(ans, all+submax+right);
                // cout << i << " "<< j << " " << k << " " << all << " " << submax << " " << right << endl;
                submax = max(submax, (tate[j-1][k]-tate[i][k])-yoko[j][k-1]-yoko[i][k-1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}