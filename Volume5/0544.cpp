#include<iostream>
using namespace std;

int n, m;

int main(){
    while(cin >> n >> m){
        if(n + m == 0)  break;

        int diff[n+1];
        for(int i = 1; i < n+1; i++)    cin >> diff[i];
        int pos = 1;

        int x, ans;
        for(int i = 0; i < m; i++){
            cin >> x;
            pos = pos + x + diff[pos+x];
            if(pos >= n){
                ans = i+1;
                for(int j = i+1; j < m; j++)  cin >> x;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}