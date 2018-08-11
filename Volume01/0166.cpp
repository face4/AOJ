#include<iostream>
#include<cmath>
using namespace std;

#define PI 2 * acos(0.0)
#define DEGtoRAD(X) (X*PI)/180.0
#define EPS 1e-06

int main(){
    int m, n, v;
    while(1){
        cin >> m;
        if(m == 0)  break;

        double first = 0, second = 0;

        int rest = 360;
        for(int i = 0; i < m-1; i++){
            cin >> v;
            first += sin(DEGtoRAD(v));
            rest -= v;
        }
        first += sin(DEGtoRAD(rest));

        cin >> n;
        rest = 360;
        for(int i = 0; i < n-1; i++){
            cin >> v;
            second += sin(DEGtoRAD(v));
            rest -= v;
        }
        second += sin(DEGtoRAD(rest));

        if(first - second > EPS)        cout << 1 << endl;
        else if(first - second < -EPS)  cout << 2 << endl;
        else                            cout << 0 << endl;
    }
    return 0;
}