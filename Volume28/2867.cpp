#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int c[n], a[n];
    for(int i = 0; i < n; i++)  a[i] = 0, cin >> c[i];

    int q;
    cin >> q;

    int t, x, d;
    while(q-- > 0){
        cin >> t >> x >> d;
        x--;
        if(t == 1){
            a[x] += d;
            if(a[x] > c[x]){
                cout << x+1 << endl;
                return 0;
            }
        }else if(t == 2){
            a[x] -= d;
            if(a[x] < 0){
                cout << x+1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}