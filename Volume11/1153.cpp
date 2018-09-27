#include<iostream>
#include<set>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        set<int> taro, hanako;
        int x, h = 0, t = 0;
        for(int i = 0; i < n; i++)  cin >> x, taro.emplace(x), t += x;
        for(int j = 0; j < m; j++)  cin >> x, hanako.emplace(x), h += x;
        int diff = h-t;
        if(abs(diff) % 2 == 1){
            cout << -1 << endl;
            continue;
        }
        diff /= 2;
        int ansa = -1, ansb = -1;
        for(int k : taro){
            if(hanako.count(k+diff)){
                ansa = k, ansb = k+diff;
                break;
            }
        }
        if(ansa == -1)  cout << -1 << endl;
        else            cout << ansa << " " << ansb << endl;
    }
    return 0;
}