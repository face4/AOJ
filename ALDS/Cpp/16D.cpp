#include<iostream>
#include<algorithm>
using namespace std;

int n, A[1000], s;
int B[1000], T[10001];

int solve(){
    int ans = 0;

    bool V[1000] = {};
    for(int i = 0; i < n; i++){
        B[i] = A[i];
    }

    sort(B, B+n);

    // 配列Tは要素->ソート後の位置をO(1)で取得するためのもの
    for(int i = 0; i < n; i++)  T[B[i]] = i;
    for(int i = 0; i < n; i++){
        if(V[i])    continue;
        int cur = i;
        int sum = 0;
        int tmpmin = 10000;
        int an = 0;
        while(1){
            V[cur] = true;
            an++;
            int v = A[cur];
            tmpmin = min(tmpmin,v);
            sum += v;
            cur = T[v];
            if(V[cur])  break;
        }
        ans += min(sum + (an-2)*tmpmin, tmpmin + sum + (an+1) * s);
    }

    return ans;
}

int main(){
    cin >> n;

    s = 10000;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        s = min(s, A[i]);
    }

    cout << solve() << endl;
    return 0;
}