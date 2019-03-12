#include<iostream>
#include<vector>
using namespace std;

struct UF{
    int n;
    vector<int> p, club;
    
    UF(int siz){
        n = siz;
        p.resize(n);
        club.resize(n, -1);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int getparent(int x){
        if(p[x] != x){
            p[x] = getparent(p[x]);
        }
        return p[x];
    }

    bool same(int x, int y){
        return getparent(x)==getparent(y);
    }

    bool unite(int x, int y){
        x = getparent(x), y = getparent(y);
        if(club[x] == -1){
            p[x] = y;
            return true;
        }else if(club[y] == -1){
            p[y] = x;
            return true;
        }else if(club[x] == club[y]){
            return true;
        }
        return false;
    }

    bool assign(int x, int val){
        x = getparent(x);
        if(club[x] == -1 || club[x] == val){
            club[x] = val;
            return true;
        }
        return false;
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    UF uf(n);
    int a, b, c;
    for(int i = 1; i <= k; i++){
        cin >> a >> b >> c;
        b--, c--;
        bool act = true;
        if(a == 1){
            act = uf.unite(b, c);
        }else{
            act = uf.assign(b, c);
        }
        if(!act){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}