#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    n %= 12;
    for(int i = 0; i < n; i++){
        if(i%2 == 0)    a = a-b;
        else            b = a+b;
    }
    cout << a << " " << b << endl;
    return 0;
}
