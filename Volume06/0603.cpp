#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int b[n];
    b[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if(a[i] != a[i+1])  b[i] = b[i+1] + 1;
        else                b[i] = 1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp = b[i];
        int cur = i + tmp;
        if(cur < n) tmp += b[cur], cur += b[cur];
        if(cur < n) tmp += b[cur], cur += b[cur];
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}