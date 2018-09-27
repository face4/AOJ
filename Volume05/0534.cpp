#include<iostream>
using namespace std;

int arr[10002];

int main(){
    int n;
    while(cin >> n, n){
        char x;
        // 4は番兵
        arr[0] = 4;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        arr[n+1] = 4;

        int delMax = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                int l = i-1, r = i+1, tmpdel = 0, tmpcnt = 1, color = j;
                while(1){
                    while(arr[l] == color)   l--, tmpcnt++;
                    while(arr[r] == color)   r++, tmpcnt++;
                    if(tmpcnt >= 4) tmpdel += tmpcnt;
                    else            break;
                    tmpcnt = 0;
                    if(arr[l] != arr[r])    break;
                    color = arr[l];
                }
                delMax = max(delMax, tmpdel);
            }
        }

        cout << n - delMax << endl;
    }
    return 0;
}