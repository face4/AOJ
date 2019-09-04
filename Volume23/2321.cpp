#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int dp[1<<16] = {};
        while(n-- > 0){
            int m, l;
            cin >> m >> l;
            int bit = 0;
            while(m-- > 0){
                int s, e;
                cin >> s >> e;
                for(int i = s; i+1 <= e; i++)   bit |= (1<<(i-6));
            }
            for(int j = (1<<16)-1; j >= 0; j--){
                if(j&bit)   continue;
                dp[j] = max(dp[j], dp[j^bit]+l);
            }
        }
        cout << *max_element(dp, dp+(1<<16)) << endl;
    }
}