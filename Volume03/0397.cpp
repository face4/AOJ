// O(sqrt(A_max) * N)で間に合うはず
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

struct UF{
    vector<int> p;
    UF(int siz){
        p.resize(siz);
        for(int i = 0; i < siz; i++)    p[i] = i;
    }

    int findSet(int x){
        if(p[x] != x)   p[x] = findSet(p[x]);
        return p[x];
    }

    void unite(int x, int y){
        x = findSet(x), y = findSet(y);
        p[y] = x;
    }
    
    bool isSame(int x, int y){
        return findSet(x)==findSet(y);
    }
};

int main(){
    vector<bool> np(100001, 0);
    vector<int> p;
    for(int i = 2; i < 100001; i++){
        if(np[i])   continue;
        p.push_back(i);
        for(int j = i+i; j < 100001; j += i){
            np[j] = true;
        }
    }
    int base = p.size();
    UF uf(base + 100001);
    auto pos = [&](int val)->int{
        return lower_bound(p.begin(), p.end(), val)-p.begin();
    };
    int n;  cin >> n;
    vector<int> v(n), x(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];    x[i] = v[i];
        for(int j = 2; j*j <= x[i]; j++){
            if(x[i]%j > 0)   continue;
            while(x[i]%j == 0)  x[i] /= j;
            uf.unite(pos(j), base+v[i]);
        }
        if(x[i] != 1)   uf.unite(pos(x[i]), base+v[i]);
        x[i] = v[i];
    }

    sort(x.begin(), x.end());
    bool ok = true;
    for(int i = 0; i < n; i++){
        ok &= uf.isSame(base+v[i], base+x[i]);
    }
    cout << ok << endl;
    return 0;
}