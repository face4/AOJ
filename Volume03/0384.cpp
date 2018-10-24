#include<iostream>
using namespace std;
typedef long long ll;

int digitSum(ll x){
    int ret = 0;
    while(x > 0){
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main(){
    int a, n, m;
    cin >> a >> n >> m;

    int ans = 0;
    for(int i = 1;;i++){
        ll tmp = 1;
        for(int j = 0; j < n; j++){
            tmp *= (i+a);
        }
        if(tmp > m) break;
        if(digitSum(tmp) == i)  ans++;
    }

    cout << ans << endl;

    return 0;
}