#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    priority_queue<pair<int,int>> l, r;
    int ans = 0, cur = 0;
    do{
        for(int j = 0; j < m; j++)  l.push({-a[cur%n], cur}), r.push({a[cur%n], cur}), cur++;
        while(!inRange(l.top().second, cur-m, cur)) l.pop();
        while(!inRange(r.top().second, cur-m, cur)) r.pop();
        ans += r.top().first+l.top().first;
    }while(cur%n);
    cout << ans << endl;
    return 0;
}