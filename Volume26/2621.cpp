// 答えとなる領域は必ず面積1(だと思う)
#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,map<int,int>> m;
    while(n-- > 0){
        int x, y, w;
        cin >> x >> y >> w;
        m[x][y] += w;
    }
    auto getter = [&](int x, int y)->int{
        return m.count(x) && m[x].count(y) ? m[x][y] : 0;
    };
    int ans = 0;
    for(auto p : m){
        int x = p.first;
        for(auto q : p.second){
            int y = q.first, w = q.second;
            for(int i : {-1, 1}){
                for(int j : {-1, 1}){
                    ans = max(ans, w+getter(x+i,y)+getter(x,y+j)+getter(x+i,y+j));
                }
            }
        }
    }
    cout << ans << " / 1" << endl;
    return 0;
}