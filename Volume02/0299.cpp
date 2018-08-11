// pを基準(0)として座標を変換し、反時計回りにd[0]まで行くパターン、
// 時計回りにd[m-1]まで行くパターン、d[i]まで時計回りで行って反時計回りで
// d[i+1]まで行くパターン、d[i+1]まで反時計回りで行ってd[i]まで時計回り
// で行くパターンを全て試し、最小値を取る

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    
    vector<int> d(m);
    for(int i = 0; i < m; i++){
        cin >> d[i];
        d[i] = (d[i] - p + n)%n;
    }

    sort(d.begin(), d.end());
    
    int ans = min(n-d[0], d[m-1]);

    for(int i = 0; i < m-1; i++){
        ans = min(ans, min(2*d[i] + n-d[i+1], 2*(n-d[i+1]) + d[i]));
    }
    
    cout << ans*100 << endl;

    return 0;
}