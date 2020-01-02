#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
typedef long long ll;

int main(){
    int x[4], y[4];
    while(cin >> x[0], x[0] < 4){
        cin >> y[0];
        for(int i = 1; i < 4; i++)  cin >> x[i] >> y[i];
        vector<int> v;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                int origin = i*4+j;
                for(int k = 0; k < 4; k++){
                    int ni = i+x[k], nj = j+y[k];
                    if(!inRange(ni,0,4)||!inRange(nj,0,4))  continue;
                    int next = ni*4+nj;
                    v.push_back((1<<origin) + (1<<next));
                }
            }
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        vector<ll> dp(1<<16, 0);
        dp[0] = 1;
        for(int s = 0; s < 1<<16; s++){
            for(int j : v){
                if((s&j) == 0)  dp[s^j] += dp[s];
            }
        }
        cout << dp.back()/40320 << endl;
    }
    return 0;
}