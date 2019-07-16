#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int n, v[2000];
ll dp[2000][2000][2] = {};
bool visit[2000][2000][2] = {};

void joi(int op, int &a, int &b, int &c){
    if(op == 0){
        if(c == 0)  a++;
        else        a--;
        if(a < 0)   c = 0, a = b, b = n-1;
    }
    if(op == 1){
        if(c == 0)  b--;
        else        b++;
        if(b > n-1) c = 0, b = a, a = 0;
    }
}

void ioi(int &a, int &b, int &c){
    if(v[a] > v[b])         joi(0, a, b, c);
    else if(v[a] < v[b])    joi(1, a, b, c);
}

ll dfs(int x, int y, int z){
    if(visit[x][y][z])  return dp[x][y][z];

    visit[x][y][z] = true;

    // base
    if(x == y){
        return dp[x][y][z] = v[x];
    }
    if(abs(y-x) == 1 || (min(x,y)==0&&max(x,y)==n-1)){
        return dp[x][y][z] = max(v[x],v[y]);
    }

    int cx, cy, cz;
    // take x
    cx = x, cy = y, cz = z;
    joi(0, cx, cy, cz);
    ioi(cx, cy, cz);
    dp[x][y][z] = max(dp[x][y][z], v[x]+dfs(cx, cy, cz));

    // take y
    cx = x, cy = y, cz = z;
    joi(1, cx, cy, cz);
    ioi(cx, cy, cz);
    dp[x][y][z] = max(dp[x][y][z], v[y]+dfs(cx, cy, cz));

    return dp[x][y][z];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> v[i];
    
    // stupid
    if(n == 1){
        cout << v[0] << endl;
        return 0;
    }else if(n == 2){
        cout << max(v[0], v[1]) << endl;
        return 0;
    }

    // idiot
    int x = 1, y = n-1, z = 0;
    if(v[x] > v[y]) x++;
    else            y--;
    ll ans = v[0] + dfs(x, y, z);
    x = 0, y = n-2, z = 0;
    if(v[x] > v[y]) x++;
    else            y--;
    ans = max(ans, v[n-1] + dfs(x, y, z));

    for(int i = 1; i < n-1; i++){
        x = i-1, y = i+1, z = 1;
        ioi(x, y, z);
        ans = max(ans, v[i]+dfs(x,y,z));
    }
    cout << ans << endl;
    return 0;
}