#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int a[n];
        double ave = 0;
        for(int i = 0; i < n; i++)  cin >> a[i], ave += a[i];
        ave /= n;
        sort(a, a+n);
        cout << upper_bound(a,a+n,ave) - a << endl;
    }
    return 0;
}