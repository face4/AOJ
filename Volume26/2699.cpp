#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int d, e;
    while(cin >> d >> e, d+e){
        double ans = 10000;
        for(int i = 0; i < d; i++){
            ans = min(ans, abs(sqrt(pow(i,2)+pow(d-i,2))-e));
        }
        cout << ans << endl;
    }
    return 0;
}