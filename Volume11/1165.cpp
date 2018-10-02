#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int x[n], y[n];
        x[0] = y[0] = 0;
        
        int a, b;
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            x[i] = x[a], y[i] = y[a];
            if(b == 0)  x[i]--;
            if(b == 1)  y[i]--;
            if(b == 2)  x[i]++;
            if(b == 3)  y[i]++;
        }

        int lx = 0, rx = 0, uy = 0, dy = 0;
        for(int i = 0; i < n; i++){
            lx = min(lx, x[i]);
            rx = max(rx, x[i]);
            uy = max(uy, y[i]);
            dy = min(dy, y[i]);
        }

        cout << rx-lx+1 << " " << uy-dy+1 << endl;
    }
    return 0;
}