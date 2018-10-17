#include<iostream>
using namespace std;

int money, y, n, op, fee;
double p;

int calc(){
    int m = money;
    if(op == 0){
        int ex = 0;
        for(int i = 0; i < y; i++){
            ex += m*p;
            m -= fee;
        }
        return ex + m;
    }else{
        for(int i = 0; i < y; i++){
            m = m*(1.0+p)-fee;
        }
        return m;
    }
}

int main(){
    int q;
    cin >> q;

    while(q-- > 0){
        int ans = 0;

        cin >> money >> y >> n;

        for(int i = 0; i < n; i++){
            cin >> op >> p >> fee;
            ans = max(ans, calc());
        }

        cout << ans << endl;
    }

    return 0;
}