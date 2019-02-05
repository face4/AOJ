#include<iostream>
#include<vector>
using namespace std;

int main(){
    int d, x, p, y;
    string a;
    
    cin >> d;
    vector<int> dp(d+1, 0);
    
    cin >> x;
    for(int i = 0; i < x; i++){
        cin >> a >> p;
        if(a != "D")    continue;
        for(int j = d-1; j >= 0; j--)   dp[j+1] = max(dp[j+1], dp[j]+p);
    }
    
    cin >> y;
    for(int i = 0; i < y; i++){
        cin >> a >> p;
        if(a != "DD")   continue;
        for(int j = d-2; j >= 0; j--)   dp[j+2] = max(dp[j+2], dp[j]+p);
    }

    cout << dp[d] << endl;

    // int d, x, y;
    // cin >> d >> x;

    // vector<int> v;
    // char a;
    // int p;
    // for(int i = 0; i < x; i++){
    //     cin >> a >> p;
    //     if(a == 'D')    v.push_back(p);
    //     else            v.push_back(0);
    // }

    // cin >> y;
    // string bc;
    // int q;
    // for(int i = 0; i < y; i++){
    //     cin >> bc >> q;
    //     if(bc == "DD")  v.push_back(q);
    //     else            v.push_back(0);
    // }

    // int ans = 0;
    // for(int s = 0; s < 1<<(x+2*y); s++){
    //     int popcnt = 0, score = 0;
    //     for(int j = 0; j < x; j++){
    //         if((s>>j)&1)    popcnt++, score += v[j];
    //     }
    //     for(int j = 0; j < y; j++){
    //         if((s>>(x+2*j))&1 && (s>>(x+2*j+1))&1)  popcnt += 2, score += v[x+j];
    //     }
    //     if(popcnt <= d) ans = max(ans, score);
    // }

    // cout << ans << endl;

    return 0;
}