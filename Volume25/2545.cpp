#include<iostream>
using namespace std;

int a[7], n, x, m, l[10], r[10], s[10], b[7] = {-1}, bsum = -1, c[7] = {};

void dfs(int i){
    if(i == n+1){
        int tmpsum = 0;
        for(int j = 1; j <= n; j++) c[j] = c[j-1]+a[j], tmpsum+=a[j];
        if(tmpsum <= bsum)  return;
        bool valid = true;
        for(int j = 0; j < m; j++){
            valid &= s[j]==c[r[j]]-c[l[j]-1];
        }
        if(valid){
            for(int j = 1; j <= n; j++) b[j] = a[j];
            bsum = tmpsum;
        }
        return;
    }
    for(int j = 0; j <= x; j++){
        a[i] = j;
        dfs(i+1);
    }
}

int main(){
    cin >> n >> x >> m;
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i] >> s[i];
    }
    dfs(1);
    if(bsum == -1){
        cout << -1 << endl;
    }else{
        for(int i = 1; i <= n; i++) cout << b[i] << " \n"[i==n];
    }
    return 0;
}