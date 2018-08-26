#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int ans = 0, a;
        for(int i = 0; i < n/4; i++){
            cin >> a;
            ans += a;
        }
        cout << ans << endl;
    }
    return 0;
}