#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int q;
    cin >> q;

    while(q-- > 0){
        int k;
        cin >> k;
        cout << (a[lower_bound(a, a+n, k)-a] == k) << endl;
    }

    return 0;
}