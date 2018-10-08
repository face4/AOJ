#include<iostream>
using namespace std;

int n, l, r;

bool check(int x, int *a){
    int i;
    for(i = 0; i < n; i++)  if(x % a[i] == 0)  break;
    if(i != n){
        return i%2 == 0;
    }else{
        return n%2 == 0;
    }
}

int main(){
    while(cin >> n >> l >> r, n+l+r){
        int a[n];
        for(int i = 0; i < n; i++)  cin >> a[i];
        int cnt = 0;
        for(int x = l; x <= r; x++) if(check(x, a)) cnt++;
        cout << cnt << endl;
    }
    return 0;
}