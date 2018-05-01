#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 40
vector<int> pre, in, post;
int n, pos;

void rec(int l, int r){
    if(l >= r)  return;
    int next = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), next));
    rec(l, m);
    rec(m+1, r);
    post.push_back(next);
}

void solve(){
    pos = 0;
    rec(0, pre.size());
    for(int i = 0; i < post.size(); i++){
        if(i)   cout << " ";
        cout << post[i];
    }
    cout << endl;
}

int main(){
    cin >> n;

    int k;
    for(int i = 0; i < n; i++){
        cin >> k;
        pre.push_back(k);
    }

    for(int i = 0; i < n; i++){
        cin >> k;
        in.push_back(k);
    }

    solve();

    return 0;
}