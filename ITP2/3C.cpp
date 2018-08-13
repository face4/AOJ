#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int q;
    cin >> q;

    int b, e, k;
    for(int i = 0; i < q; i++){
        cin >> b >> e >> k;
        int cnt = 0;
        for(int i = b; i < e; i++)  cnt += (a[i] == k);
        cout << cnt << endl;
    }

    return 0;
}