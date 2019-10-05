#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    sort(x, x+n);
    cout << (x[n-1]-x[0]+1)/2 << endl;
    return 0;
}