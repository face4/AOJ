#include<iostream>
using namespace std;

int main(){
    int sum[1001] = {}, cnt[1001] = {};
    for(int i = 1; i <= 1000; i++)  sum[i] = sum[i-1] + i;

    for(int i = 0; i <= 1000; i++){
        for(int j = i+2; j <= 1000; j++){
            if(sum[j]-sum[i] > 1000)    continue;
            cnt[sum[j]-sum[i]]++;
        }
    }

    int n;
    while(cin >> n, n)  cout << cnt[n] << endl;

    return 0;
}