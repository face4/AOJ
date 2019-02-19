#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int t;
    cin >> t;

    while(t-- > 0){
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        int n;
        cin >> n;
        int a, b, cnt = 0;
        while(n-- > 0){
            cin >> a >> b;
            if(inRange(a, x, x+w) && inRange(b, y, y+h))    cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}