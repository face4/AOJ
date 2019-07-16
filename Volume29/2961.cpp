#include<iostream>
using namespace std;

int main(){
    int memo[100001] = {};
    for(int i = 2; i < 100001; i++){
        int cnt = 0;
        for(int j = 2; j*j <= i; j++){
            if(i%j) continue;
            cnt++;
        }
        if(cnt > 1) memo[i]++;
    }
    for(int i = 2; i < 100001; i++) memo[i] += memo[i-1];

    int q;
    cin >> q;
    while(q-- > 0){
        int n;  cin >> n;
        cout << memo[n] << endl;
    }
    return 0;
}
