#include<iostream>
#include<map>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n, k;
    cin >> n >> k;

    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++){
        map<pair<int,int>,int> m;
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            int diffx = x[j]-x[i], diffy = y[j]-y[i];
            if(diffx < 0)   diffx *= -1, diffy *= -1;
            int g = gcd(abs(diffx), abs(diffy));
            diffx /= g, diffy /= g;
            if(++m[{diffx,diffy}] >= k-1){
                cout << 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}