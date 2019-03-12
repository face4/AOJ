#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        int x = 0, y = 0, dx, dy, ma = 0, ansx, ansy;
        while(cin >> dx >> dy, dx+dy){
            x += dx, y += dy;
            if(x*x+y*y > ma || (x*x+y*y == ma && x > ansx)){
                ma = x*x + y*y;
                ansx = x, ansy = y;
            }
        }
        cout << ansx << " " << ansy << endl;
    }
    return 0;
}