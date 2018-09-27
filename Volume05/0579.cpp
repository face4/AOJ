#include<iostream>
#include<map>
using namespace std;
#define inRange(x, a, b) (a <= x && x <= b)

int temp[200], a[200], b[200], c[200];
int dp[200] = {};

int main(){
    int d, n;
    cin >> d >> n;
    
    for(int i = 0; i < d; i++)  cin >> temp[i];
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i] >> c[i];

    map<int, int> y;
    for(int close = 0; close < n; close++){
        if(inRange(temp[0], a[close], b[close]))    y[close] = 0;
    }

    for(int day = 1; day < d; day++){
        map<int, int> t;
        for(int close = 0; close < n; close++){
            if(!inRange(temp[day], a[close], b[close])) continue;

            int tmp = 0;
            for(pair<int,int> x : y)  tmp = max(tmp, x.second + abs(c[x.first]-c[close]));
            t[close] = tmp;
        }
        y = t;
    }

    int ans = 0;
    for(pair<int,int> x : y){
        ans = max(ans, x.second);
    }

    cout << ans << endl;

    return 0;
}