#include<iostream>
using namespace std;

int main(){
    int n;
    int a[4] = {10, 50, 100, 500};
    bool first = true;
    while(cin >> n, n){
        int coin[4], oturi[4];
        for(int i = 0; i < 4; i++)  cin >> coin[i];

        n = -n;
        for(int i = 0; i < 4; i++)  n += coin[i]*a[i];

        for(int i = 3; i >= 0; i--){
            oturi[i] = n / a[i];
            n -= oturi[i] * a[i];
        }

        if(first)   first = false;
        else        cout << endl;

        for(int i = 0; i < 4; i++){
            if(coin[i] > oturi[i])
                cout << a[i] << " " << coin[i]-oturi[i] << endl;
        }

    }
    return 0;
}