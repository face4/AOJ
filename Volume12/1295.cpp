#include<iostream>
#include<numeric>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        int a[n], b[m];
        for(int i = 0; i < n; i++)  cin >> a[i];
        for(int i = 0; i < m; i++)  cin >> b[i];

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i] == b[j]){
                    ans += a[i];
                    a[i] = b[j] = 0;
                    break;
                }
            }
        }

        ans += accumulate(a, a+n, 0) + accumulate(b, b+m, 0);

        cout << ans << endl;
    }
    return 0;
}