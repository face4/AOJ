#include<iostream>
using namespace std;

bool ng[1<<20] = {};
int popcnt[1<<20] = {};

int main(){
    int n, k;
    cin >> n >> k;
    int a[n], ret = n;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int s = 1; s < 1<<n; s++){
        int sum = 0;
        for(int i = 0; i < n; i++)  if((s>>i)&1)    sum += a[i], popcnt[s]++;
        ng[s] = sum==k;
        for(int i = 0; i < n; i++)  if((s>>i)&1)    ng[s] |= ng[s^(1<<i)];
        if(!ng[s])  ret = min(ret, n-popcnt[s]);
    }
    cout << ret << endl;
    return 0;
}