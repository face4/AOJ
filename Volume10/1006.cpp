#include<iostream>
#include<vector>
using namespace std;

int main(){
    auto f = [](int i)->int{
        return i%100 + i/100*60;
    };
    int n, p, q;
    while(cin >> n >> p >> q, n+p+q){
        p = f(p), q = f(q);
        vector<int> imos(q-p+1, 0), a(q-p+1, 0);
        for(int i = 0; i < n; i++){
            int k;  cin >> k;
            while(k-- > 0){
                int from, to;
                cin >> from >> to;
                from = f(from), to = f(to);
                from -= p, to -= p;
                imos[from]++;
                imos[to]--;
            }
        }
        for(int i = 1; i < q-p+1; i++)  imos[i] += imos[i-1];
        for(int i = 0; i < q-p+1; i++)  imos[i] = (imos[i] < n);
        int ans = imos[0];
        if(imos[0] == 1)    a[0] = 1;
        for(int i = 1; i < q-p; i++){
            if(imos[i]) a[i] = a[i-1]+1;
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}