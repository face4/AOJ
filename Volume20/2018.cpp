#include<iostream>
using namespace std;

int main(){
    int n, m, p, x;
    while(cin >> n >> m >> p, n+m+p){
        int sum = 0, hit = 0;
        for(int i = 1; i <= n; i++){
            cin >> x;
            sum += x;
            if(i == m)  hit = x;
        }
        if(hit == 0)    cout << 0 << endl;
        else            cout << (sum*100) * (100-p) / 100 / hit << endl;
    }
    return 0;
}