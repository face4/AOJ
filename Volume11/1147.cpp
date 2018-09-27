#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int sum = 0, mi = 1000, ma = 0, x;
        for(int i = 0; i < n; i++){
            cin >> x;
            sum += x;
            mi = min(mi, x);
            ma = max(ma, x);
        }
        cout << (sum-mi-ma)/(n-2) << endl;
    }
    return 0;
}