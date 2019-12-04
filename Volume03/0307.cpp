#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, r, t;
    cin >> n >> r >> t;
    
    int p[n];
    for(int i = 0; i < n; i++)  cin >> p[i];

    int ans = 0;
    vector<int> stock(r, 0);
    for(int i = 1; i <= t; i++){
        vector<int> next(r, 0);
        for(int j = 0; j < n; j++){
            int pos = i*p[j]%r;
            if(stock[pos])  stock[pos]--;
            else            ans++;
            if(i!=1)    next[pos]++;
        }
        for(int j = 0; j < r; j++)  stock[j] += next[j];
    }
    cout << ans << endl;
    return 0;
}