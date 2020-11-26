#include<iostream>
#include<vector>
#include<functional>
#include<climits>
using namespace std;

template<typename T>
struct Seg{
private:
    vector<T> node;
    int n;
    function<T(T,T)> f;
    T def;

public:
    Seg(int siz, T d, function<T(T,T)> f) : def(d), f(f) {
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, def);
    }
    Seg(vector<T> v, T d, function<T(T,T)> f) : def(d), f(f){
        n = 1;
        while(n < v.size())  n *= 2;
        node.resize(2*n-1);
        for(int i = 0; i < v.size(); i++)   node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = f(node[2*i+1], node[2*i+2]);
    }

    void update(int x, T val){
        x += n-1;
        node[x] = f(node[x], val); /* ! */
        while(x){
            x = (x-1)/2;
            node[x] = f(node[2*x+1], node[2*x+2]);
        }
    }

    T query(int a, int b){
        int L = a+n-1, R = b+n-1;
        T ret = def;
        while(L < R){
            if((R&1) == 0)  ret = f(ret, node[--R]);
            if((L&1) == 0)  ret = f(ret, node[L++]);
            L >>= 1, R >>= 1;
        }
        return ret;
    }
};

vector<int> v[200000], et;
int be[200000], en[200000], k = 0;

void dfs(int x, int p){
    be[x] = k++;
    et.push_back(x);
    for(int j : v[x]){
        if(j != p){
            dfs(j, x);
            et.push_back(x);
            k++;
        }
    }
    en[x] = k;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;  cin >> k;
        while(k--){
            int x;  cin >> x;
            v[i].push_back(x);
        }
    }
    dfs(0, -1);
    Seg<int> stsum(et.size(), 0, [](int x, int y){return x+y;});
    int q;
    cin >> q;
    while(q--){
        int op, a, b;
        cin >> op >> a;
        if(op == 0){
            cin >> b;
            stsum.update(be[a]-1, b);
            stsum.update(en[a], -b);
        }else{
            cout << stsum.query(0, be[a]) << endl;
        }
    }
    return 0;
}