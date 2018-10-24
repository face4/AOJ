#include<iostream>
using namespace std;

int main(){
    int a, b, x;
    cin >> a >> b >> x;

    int ans = 0;
    if(a <= b){
        ans = (x+999)/1000 * a;
    }else if(2*b < a){
        ans = (x+499)/500 * b;
    }else{
        ans = x/1000 * a;
        x %= 1000;
        ans += min(a, (x+499)/500*b);
    }

    cout << ans << endl;

    return 0;
}