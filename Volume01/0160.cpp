#include<iostream>
using namespace std;

int size(int x){
    if(x > 160) return 6;
    if(x > 140) return 5;
    if(x > 120) return 4;
    if(x > 100) return 3;
    if(x > 80) return 2;
    if(x > 60) return 1;
    return 0;
}

int weight(int x){
    if(x > 25) return 6;
    if(x > 20) return 5;
    if(x > 15) return 4;
    if(x > 10) return 3;
    if(x > 5) return 2;
    if(x > 2) return 1;
    return 0;
}

int price[7] = {600, 800, 1000, 1200, 1400, 1600, 0};

int main(){
    while(1){
        int n, x, y, h, w;
        cin >> n;

        if(n == 0)  break;

        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> h >> w;
            sum += price[max(size(x+y+h), weight(w))];
        }

        cout << sum << endl;
    }
    return 0;
}