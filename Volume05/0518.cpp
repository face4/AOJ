#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int x[n], y[n];
        
        static bool exist[5001][5001] = {};

        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
            exist[x[i]][y[i]] = true;
        }

        int ans = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n; j++){
                int ax = x[i], ay = y[i], bx = x[j], by = y[j];
                int cx = ax - (by-ay), cy = ay + (bx-ax);
                int dx = cx + (bx-ax), dy = cy + (by-ay);
                if(0 <= cx && cx < 5001 && 0 <= cy && cy < 5001 && 
                   0 <= dx && dx < 5001 && 0 <= dy && dy < 5001 && 
                   exist[cx][cy] && exist[dx][dy]){
                       ans = max(ans, (bx-ax)*(bx-ax) + (by-ay)*(by-ay));
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}