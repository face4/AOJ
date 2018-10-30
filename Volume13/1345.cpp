#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int calc(vector<int> a, vector<int> b){
    int apos = 0, bpos = 0, ret = 0;
    while(apos < a.size()){
        while(a[apos] != 1) apos++;
        while(b[bpos] != 1) bpos++;
        ret += abs(bpos-apos);
        apos++;
        bpos++;
    }
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> b(n), p(m);
    for(int i = 0; i < n; i++)  cin >> b[i];
    for(int j = 0; j < m; j++)  cin >> p[j];

    vector<int> c;
    for(int j = 0; j < m; j++){
        int add = (j % 2 == 0);
        for(int k = 0; k < p[j]; k++)   c.push_back(add);
    }

    // sentinel
    b.push_back(1);
    c.push_back(1);

    int one = accumulate(b.begin(), b.end(), 0);

    int ans = 1<<21;
    if(accumulate(c.begin(), c.end(), 0) == one){
        ans = min(ans, calc(b, c));
    }

    for(int i = 0; i < n; i++)  c[i] = 1 - c[i];
    if(accumulate(c.begin(), c.end(), 0) == one){
        ans = min(ans, calc(b, c));
    }

    cout << ans << endl;

    return 0;
}