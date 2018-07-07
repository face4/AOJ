// bit-DP
// dp[i][j] := 最後にiを詰めてビット列がjとなったときの幅の最小値(恐らく)

#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

double INF = 1000.0;

int main(){
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        int w;
        ss >> w;

        vector<double> rad;
        double next; 
        int n = 0;
        
        while(ss >> next){
            rad.push_back(next);
            n++;
        }

        double dp[n][1<<n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 1<<n; j++){
                dp[i][j] = 10000;
            }
        }

        for(int i = 0; i < n; i++){
            dp[i][1<<i] = rad[i];
        }

        for(int s = 1; s < 1<<n; s++){
            for(int i = 0; i < n; i++){
                if(!((1<<i) & s)) continue;
                for(int j = 0; j < n; j++){
                    if((1<<j) & s)  continue;
                    double tmp = dp[i][s] + 2*sqrt(rad[i]*rad[j]);
                    if(tmp < dp[j][s | (1<<j)]){
                        dp[j][s | (1<<j)] = tmp;
                    }
                }
            }
        }

        double ans = INF;
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[i][(1<<n)-1] + rad[i]);
        }

        cout << (ans <= w ? "OK" : "NA") << endl;
    }
    return 0;
}