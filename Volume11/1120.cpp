#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, r;
    while(cin >> n >> r, n+r){
        int arr[n];
        for(int i = 0; i < n; i++)  arr[i] = n-i;
        int p, c;
        for(int i = 0; i < r; i++){
            cin >> p >> c;
            int next[n], pos = 0;
            for(int j = p-1; j < p-1+c; j++)  next[pos++] = arr[j];
            for(int j = 0; j < p-1; j++)    next[pos++] = arr[j];
            for(int j = p-1+c; j < n; j++)    next[pos++] = arr[j];
            copy(next, next+n, arr);
        }
        cout << arr[0] << endl;
    }
    return 0;
}