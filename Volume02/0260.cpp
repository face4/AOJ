#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    while(cin >> n, n){
        ll p, sum = 0;
        for(int i = 0; i < n; i++)  cin >> p, sum += p;
        vector<int> j(n-1);
        for(int i = 0; i < n-1; i++)    cin >> j[i];
        sort(j.rbegin(), j.rend());
        ll ans = sum*n;
        for(int i = 0; i < n-1; i++){
            sum += j[i];
            ans = max(ans, sum*(n-i-1));
        }
        cout << ans << endl;
    }
    return 0;
}