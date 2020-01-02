// 解説を見た　こんなの思い付けない
#include<iostream>
#include<cstring>
using namespace std;

int a[10010], b[10010];

void calc(int x, int y){
    memset(b, 0, sizeof(b));
    x *= 10;
    for(int i = 1; i <= 10009; i++){
        b[i] = x/y;
        x %= y;
        x *= 10;
    }
    int carry = 0;
    for(int i = 10009; i >= 0; i--){
        a[i] += b[i]+carry;
        carry = 0;
        if(a[i] >= 10)   a[i] -= 10, carry++;
    }
}

int main(){
    int n, k, m, r;
    while(cin>>n>>k>>m>>r, n){
        memset(a, 0, sizeof(a));
        calc(1, n);
        if(m == 1){
            for(int i = 1; i <= n-1; i++){
                calc(1, n*i);
            }
        }
        cout << a[0] << ".";
        for(int i = 0; i < r; i++)  cout << a[1+i];
        cout << endl;
    }
    return 0;
}