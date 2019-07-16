#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        vector<int> xi[2525], yj[2525];
        vector<vector<int>> dp(2525, vector<int>(2525,1<<30));
        int gi = -1, gj = -1, ma = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                string s;   cin >> s;
                if(isdigit(s[0])){
                    int num = stoi(s);
                    ma = max(ma, num);
                    xi[num].push_back(i), yj[num].push_back(j);
                }else if(s == "S"){
                    xi[0].push_back(i), yj[0].push_back(j);
                }else if(s == "G"){
                    gi = i, gj = j;
                }
            }
        }
        ma++;
        xi[ma].push_back(gi), yj[ma].push_back(gj);
        dp[0][0] = 0;
        for(int i = 0; xi[i+1].size(); i++){
            for(int j = 0; j < xi[i].size(); j++){
                for(int k = 0; k < xi[i+1].size(); k++){
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + abs(xi[i][j]-xi[i+1][k])+abs(yj[i][j]-yj[i+1][k]));
                }
            }
        }
        cout << dp[ma][0] << endl;
    }
    return 0;
}