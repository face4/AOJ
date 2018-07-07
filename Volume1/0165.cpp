#include<iostream>
using namespace std;

bool nonprime[1000001] = {};
int accum[1000001] = {};

int main(){
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i <= 1000000; i++){
        if(!nonprime[i]){
            for(int j = i+i; j <= 1000000; j+=i){
                nonprime[j] = true;
            }
        }
    }

    for(int i = 2; i <= 1000000; i++){
        if(nonprime[i-1]){
            accum[i] = accum[i-1];
        }else{
            accum[i] = accum[i-1] + 1;
        }
    }

    while(1){
        int n;
        cin >> n;
        if(n == 0)  break;

        int ans = 0;

        for(int i = 0; i < n; i++){
            int p, m;
            cin >> p >> m;

            int cnt = accum[min(p+m, 1000000)] - accum[max(0, p-m)];
            if(p+m <= 1000000 && !nonprime[p+m])    cnt++;

            if(cnt == 0)    ans--;
            else            ans += cnt-1;
        }
        
        cout << ans << endl;
    }

    return 0;
}