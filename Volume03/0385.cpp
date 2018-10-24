#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    int cnt = 0;
    for(int i = 0; i < n; i++)  cnt += (a[i] != b[i]);

    int q;
    scanf("%d", &q);

    int x[q], y[q];
    for(int i = 0; i < q; i++){
        scanf("%d %d", x+i, y+i);
        x[i]--, y[i]--;
    }

    int ans;
    for(ans = 0; cnt != 0 && ans < q; ans++){
        if(a[x[ans]] == a[y[ans]])  continue;

        if(a[x[ans]] == b[x[ans]])  cnt++;
        else if(a[y[ans]] == b[x[ans]]) cnt--;

        if(a[y[ans]] == b[y[ans]])  cnt++;
        else if(a[x[ans]] == b[y[ans]]) cnt--;
        
        swap(a[x[ans]], a[y[ans]]);
    }

    if(cnt) cout << -1 << endl;
    else    cout << ans << endl;

    return 0;
}