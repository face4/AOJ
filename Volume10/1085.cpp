#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, s;
    while(cin >> n >> s, n+s){
        vector<int> r(n);
        for(int i = 0; i < n; i++)  cin >> r[i];
        sort(r.begin(), r.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (int)(r.end()-upper_bound(r.begin(), r.end(), s-r[i]));
            if(r[i]+r[i] > s)   ans--;
        }
        cout << ans/2 << endl;
    }
    return 0;
}