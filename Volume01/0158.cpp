#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0)  break;

        int ans = 0;
        while(n != 1){
            ans++;
            if(n%2)   n = 3*n+1;
            else        n /= 2;
        }

        cout << ans << endl;
    }
    return 0;
}