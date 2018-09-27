#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int a[n];
        for(int i = 0; i < n; i++)  cin >> a[i];
        sort(a, a+n);

        for(int i = 1; i < n; i++)  a[i] += a[i-1];
        
        cout << accumulate(a, a+n, 0) << endl;
    }
    return 0;
}