#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

ll ret = -1;
ll x;
int n, c;

bool isPrime(ll tmp){
    for(ll i = 2; i*i <= tmp; i++){
        if(tmp%i == 0)    return false;
    }
    return tmp!=1;
}

ll apow(int s){
    ll ret = 1;
    while(s-- > 0)  ret *= 10;
    return ret;
}

void dfs(int p){
    if(isPrime(x))  ret = max(ret, x);
    if(p == 0)  return;

    for(int i = 0; i <= 9; i++){
        if(p == 1 && i == 0)    continue;
        x *= 10;
        x += i;
        x += apow(2*(n-p+1)) * i;
        dfs(p-1);
        x -= apow(2*(n-p+1)) * i;
        x /= 10;
    }
}

int main(){
    cin >> n >> c;

    if(c < 0){
        if(n == 1)  cout << 11 << endl;
        else{
            for(int i = 0; i < 2*n; i++)    cout << "9";
            cout << endl;
        }
    }else{
        x = c;
        dfs(n);
        cout << ret << endl;
    }

    return 0;
}