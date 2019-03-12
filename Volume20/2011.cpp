#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    int n;
    while(cin >> n, n){
        vector<ll> v(n);
        vector<int> day[31];
        for(int i = 0; i < n; i++){
            int f;  cin >> f;
            while(f-- > 0){
                int x;  cin >> x;
                day[x].push_back(i);
            }
        }
        for(int i = 0; i < n; i++)  v[i] = 1ll<<i;

        int ans;
        for(ans = 1; ans <= 30; ans++){
            for(int j = 0; j < day[ans].size(); j++){
                for(int k = 0; k < day[ans].size(); k++){
                    v[day[ans][j]] |= v[day[ans][k]];
                }
            }
            bool found = false;
            for(int i = 0; i < n; i++){
                if(v[i] == (1ll<<n)-1)  found = true;
            }
            if(found)   break;
        }
        cout << (ans == 31 ? -1 : ans) << endl;
    }
    return 0;
}