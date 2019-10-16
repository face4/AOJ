#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<int> a(n, 0), b(n, 0);
        while(m-- > 0){
            int s, k;
            cin >> s >> k;
            if(k == 1){
                int x;  cin >> x;
                x--;
                a[x] += s, b[x] += s;
                continue;
            }
            while(k-- > 0){
                int x;  cin >> x;
                x--;
                b[x] += s;
            }
        }
        int ans = 0;
        multiset<int> mins;
        for(int i = 0; i < n; i++)  mins.insert(a[i]);
        for(int i = 0; i < n; i++){
            mins.erase(mins.find(a[i]));
            ans = max(ans, b[i]-*mins.begin());
            mins.insert(a[i]);
        }
        cout << ans+1 << endl;
    }
    return 0;
}