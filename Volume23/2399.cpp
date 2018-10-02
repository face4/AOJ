#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        set<int> s[n];
        for(int i = 0; i < n; i++){
            int m, p;
            cin >> m;
            while(m-- > 0){
                cin >> p;
                s[i].insert(p);
            }
        }

        int k;
        cin >> k;
        int l[k];
        for(int i = 0; i < k; i++)  cin >> l[i];

        int ans = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < k; j++)  cnt += s[i].count(l[j]);
            if(cnt == k){
                if(ans != -1){
                    ans = -1;
                    break;
                }
                ans = i+1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}