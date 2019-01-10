#include<iostream>
using namespace std;

int main(){
    int coin[6] = {1, 5, 10, 50, 100, 500};

    int ideal[500] = {};
    for(int i = 1; i < 500; i++){
        int tmp = i;
        for(int j = 5; j >= 0; j--){
            ideal[i] += tmp/coin[j];
            tmp %= coin[j];
        }
    }

    int p, n[6];
    while(cin >> p, p){
        for(int i = 0; i < 6; i++)  cin >> n[i];
        int ans = 100000;
        for(int i = 0; i < 500; i++){
            int pay = 0, tmp = p+i;
            for(int j = 5; j >= 0; j--){
                int use = min(n[j], tmp/coin[j]);
                pay += use;
                tmp -= coin[j]*use;
            }
            if(tmp) break;
            ans = min(ans, pay+ideal[i]);
        }
        cout << ans << endl;
    }

    return 0;
}