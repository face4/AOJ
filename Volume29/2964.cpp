#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << endl << flush;
    int ret;
    cin >> ret;
    return ret;
}

void answer(vector<int> v){
    cout << "!";
    for(int x : v)  cout << " " << x;
    cout << endl << flush;
}

int main(){
    int n, s, t;
    cin >> n >> s >> t;
    int d = ask(s, t);
    vector<int> use;
    for(int i = 1; i <= n; i++){
        if(ask(s, i) + ask(i, t) == d)  use.push_back(i);
    }
    vector<pair<int,int>> vp;
    for(int x : use){
        vp.push_back({ask(x, s), x});
    }
    sort(vp.begin(), vp.end());
    vector<int> ans;
    for(auto p : vp)    ans.push_back(p.second);
    answer(ans);
    return 0;
}
