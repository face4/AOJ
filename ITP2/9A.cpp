#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    set<int> a, b, c;
    int n, m, x;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        b.insert(x);
    }

    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));

    for(int x : c)  printf("%d\n", x);

    return 0;
}