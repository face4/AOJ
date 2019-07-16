#include<iostream>
using namespace std;

#define N 1000000
typedef long long ll;

ll a[N+1];
bool nonp[N+1] = {};
int val[N+1];

ll pow(ll a, ll k){
    ll ret = 1;
    while(k-- > 0)  ret *= a;
    return ret;
}

int main(){
    for(int i = 0; i < N+1; i++)    val[i] = i, a[i] = 1;
    for(int i = 2; i < N+1; i++){
        if(nonp[i]) continue;
        for(int j = i; j < N+1; j+=i){
            nonp[j] = true;
            int cnt = 0;
            while(val[j]%i == 0)    cnt++, val[j]/=i;
            a[j] *= (i-1)*pow(i, cnt-1);
        }
    }
    a[0] = 0, a[1] = 2;
    for(int i = 2; i < N+1; i++)    a[i] += a[i-1];

    int q;
    cin >> q;
    while(q-- > 0){
        int x;  cin >> x;
        cout << a[x] << endl;
    }

    return 0;
}