#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll mul = 1, add = 0;
    for(int i = 0; i < n; i++){
        int q, x;
        cin >> q >> x;
        if(q == 1){
            mul *= x, add *= x;
        }else if(q == 2){
            add += x;
        }else if(q == 3){
            add -= x;
        }
    }
    cout << -add << " " << mul << endl;
    return 0;
}
