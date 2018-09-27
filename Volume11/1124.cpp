#include<iostream>
using namespace std;

int main(){
    int n, q;
    while(cin >> n >> q, n+q){
        int m, d, ok[100] = {};
        for(int i = 0; i < n; i++){
            cin >> m;
            for(int j = 0; j < m; j++){
                cin >> d;
                ok[d]++;
            }
        }
        int ans, ma = 0;
        for(int i = 0; i < 100; i++){
            if(ok[i] > ma){
                ans = i, ma = ok[i];
            }
        }

        cout << (ma < q ? 0 : ans) << endl;
    }
    return 0;
}