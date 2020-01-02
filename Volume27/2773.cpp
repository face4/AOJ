#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    int ret = 0;
    for(int k = 1; k <= n; k++){
        if(n%k) continue;
        bool ok = true;
        for(int i = 0; i < n/k; i++){
            bool valid = true;
            for(int j = 0; j < k; j++)    valid &= a[i] == a[n/k*j+i];
            if(!valid)  ok = false;
        }
        if(ok)  ret = k;
    }
    cout << ret << endl;
    return 0;
}