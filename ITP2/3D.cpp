#include<iostream>
using namespace std;

int main(){
    int n, m;

    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++)  cin >> b[i];

    int res = -1;
    for(int i = 0; i < min(n, m); i++){
        if(a[i] == b[i])    continue;

        if(a[i] > b[i]) res = 0;
        if(a[i] < b[i]) res = 1;

        break;
    }

    if(res == -1)   res = m>n;

    cout << res << endl;

    return 0;
}