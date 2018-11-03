#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int compress(int x){
    while(x > 9){
        int tmp = 0;
        while(x > 0)    tmp += x % 10, x /= 10;
        x = tmp;
    }
    return x;
}

int n, m;
string s;
vector<int> bias, use;
int sum = 0, cnt = 0, ans = 0;

void dfs(int pos, int accum){
    if(pos == cnt){
        if(accum % 10 == 0) ans++;
        return;
    }

    for(int i = 0; i < m; i++){
        dfs(pos+1, accum + compress(bias[pos] * use[i]));
    }
}

int main(){
    cin >> n >> s >> m;
    reverse(s.begin(), s.end());
    
    for(int i = 0; i < n; i++){
        if(s[i] == '*') bias.push_back(1 + i%2), cnt++;
        else            sum += compress((1+i%2)*(s[i]-'0'));
    }

    int a;
    for(int i = 0; i < m; i++){
        cin >> a;
        use.push_back(a);
    }

    dfs(0, sum);

    cout << ans << endl;

    return 0;
}
