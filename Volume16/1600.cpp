#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int m, nmin, nmax;
    while(cin >> m >> nmin >> nmax, m+nmin+nmax){
        vector<int> p(m);
        for(int i = 0; i < m; i++)  cin >> p[i];
        sort(p.rbegin(), p.rend());
        int ans = 0, diff = 0;
        for(int i = nmin; i <= nmax; i++){
            if(p[i-1]-p[i] >= diff){
                ans = i, diff = p[i-1]-p[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}