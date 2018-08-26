#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    int dist[n+1];
    dist[1] = 0;

    for(int i = 2; i <= n; i++){
        cin >> dist[i];
        dist[i] += dist[i-1];
    }

    ll ans = 0;
    int now = 1, next;

    for(int i = 0; i < m; i++){
        cin >> next;
        if(next < 0){
            ans += dist[now] - dist[now+next];
        }else{
            ans += dist[now+next] - dist[now];
        }
        now += next;
    }

    cout << ans % 100000 << endl;

    return 0;
}