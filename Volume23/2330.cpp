#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long a = 1;
    int ans = 0;
    while(a < n){
        a *= 3;
        ans++;
    }

    cout << ans << endl;

    return 0;
}