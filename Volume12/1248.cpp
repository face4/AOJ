#include<iostream>
using namespace std;

int main(){
    int a, b, d;
    while(cin >> a >> b >> d, a+b+d){
        int ansx = 1<<20, ansy = 1<<20;
        for(int x = -10000; x <= 10000; x++){
            if(abs(d-a*x)%b)    continue;
            int tmpx = abs(x), tmpy = abs(d-a*x)/b;
            if(tmpx+tmpy < ansx+ansy || (tmpx+tmpy==ansx+ansy && a*tmpx+b*tmpy < a*ansx+b*ansy)){
                ansx = tmpx, ansy = tmpy;
            }
        }
        cout << ansx << " " << ansy << endl;
    }
    return 0;
}