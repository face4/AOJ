#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int a[4] = {25, 10, 5, 1};
    for(int i = 0; i < 4; i++){
        ans += n/a[i];
        n %= a[i];
    }
    cout << ans << endl;
    return 0;
}