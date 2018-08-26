#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;
    scanf("%d", &n);

    int x, y;
    vector<pii> vp;
    for(int i = 0; i < n; i++){
        scanf("%d %d\n", &x, &y);
        vp.push_back({x,y});
    }

    sort(vp.begin(), vp.end());
    for(pii x : vp) printf("%d %d\n", x.first, x.second);

    return 0;
}