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

    int b, e;
    for(int i = 0; i < q; i++){
        cin >> b >> e;
        reverse(a+b, a+e);
    }

    for(int i = 0; i < n; i++)  cout << a[i] << " \n"[i == n-1];

    return 0;
}