#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c, a > 0){
        int p, q, r, s;
        bool found = false;
        for(p = a; p*p >= a; p--){
            if(a%p) continue;
            r = a/p;
            for(q = -abs(c); q <= abs(c); q++){
                if(q == 0){
                    if(c != 0)  continue;
                    if(b%p == 0){
                        found = true;
                        s = b/p;
                        break;
                    }
                    if(b%r == 0){
                        found = true;
                        s = 0;
                        q = b/r;
                        break;
                    }
                }
                if(c%abs(q))    continue;
                s = c/q;
                if(p*s+q*r == b){
                    found = true;
                    break;
                }
            }
            if(found)   break;
        }
        if(found){
            if(p == r && q < s) swap(q, s);
            cout << p << " " << q << " " << r << " " << s << endl;
        }else{
            cout << "Impossible" << endl;
        }
    }
    return 0;
}