#include<iostream>
#include<algorithm>
using namespace std;

int w;

void dfs(int d, int acc, string s){
    if(acc == w){
        reverse(s.begin(), s.end());
        cout << s << endl;
        exit(0);
    }
    
    if(d >= 12) return;

    int t = 1;
    for(int i = 0; i < d; i++)  t *= 3;

    dfs(d+1, acc+t, s+"+");
    dfs(d+1, acc, s+"0");
    dfs(d+1, acc-t, s+"-");
}

int main(){
    cin >> w;
    dfs(0, 0, "");
}