#include<iostream>
#include<vector>
#include<set>
using namespace std;

int s, d;

class DisjointSet{
public:
    vector<int> p;

    DisjointSet(){}
    DisjointSet(int size){
        p.resize(size, 0);
        for(int i = 0; i < size; i++) makeSet(i);
    }
    void makeSet(int x){
        p[x] = x;
    }
    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    void unite(int x, int y){
        link(findSet(x), findSet(y));
    }
    void link(int x, int y){
        if(x == y)  return;
        if(x < s)   p[y] = x;
        else        p[x] = y;
    }
    int findSet(int x){
        if(x != p[x]){
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
    bool isHotSpring(int x){
        return findSet(x) < s;
    }
};

int main(){
    while(cin >> s >> d, s+d){
        DisjointSet uf(s+d);
        set<pair<int, pair<int,int>>> path;
        for(int i = 0; i < s; i++){
            for(int j = 0; j < d; j++){
                int x;  cin >> x;
                if(x != 0)  path.insert({x, {i, s+j}});
            }
        }
        for(int i = 0; i < d-1; i++){
            for(int j = 0; j < d-1-i; j++){
                int x;  cin >> x;
                if(x != 0)  path.insert({x, {s+i, s+i+j+1}});
            }
        }
        int ans = 0;
        bool update = true;
        while(update){
            update = false;
            for(auto it = path.begin(); it != path.end(); it++){
                auto p = *it;
                int cost = p.first, i = p.second.first, j = p.second.second;
                if(!uf.same(i, j) && (uf.isHotSpring(i)+uf.isHotSpring(j) == 1)){
                    ans += cost;
                    uf.unite(i, j);
                    path.erase(it);
                    update = true;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}