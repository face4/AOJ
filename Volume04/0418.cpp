#include<iostream>
using namespace std;

int main(){
    int x[2], y[2], w[2], h[2], lx = 0, rx = 2001, uy = 2001, dy = 0;
    for(int i = 0; i < 2; i++){
        cin >> x[i] >> y[i] >> w[i] >> h[i];
        lx = max(lx, x[i]);
        rx = min(rx, x[i]+w[i]);
        uy = min(uy, y[i]+h[i]);
        dy = max(dy, y[i]);
    }
    cout << w[0]*h[0]+w[1]*h[1] - 2*max(0,rx-lx)*max(0,uy-dy) << endl;
    return 0;
}