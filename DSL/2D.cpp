#include<iostream>
#include<vector>
using namespace std;

const int INF = 2147483647;

struct STlazy{
    int n;
    vector<int> dat, lazy;

    STlazy(vector<int> ini){
        int siz = ini.size();
        n = 1;
        while(n < siz)    n *= 2;
        dat.resize(2*n-1, INF);
        lazy.resize(2*n-1, -1);
    }

    void eval(int k, int l, int r){
        if(lazy[k] != -1){
            dat[k] = lazy[k];
            if(r-l > 1){
                lazy[2*k+1] = lazy[k];
                lazy[2*k+2] = lazy[k];
            }
            lazy[k] = -1;
        }
    }

    // [a, b)のlazyにxを入れる
    void update(int a, int b, int x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(b <= l || r <= a)    return;
        if(a <= l && r <= b){
            lazy[k] = x;
            eval(k, l, r);
            return;
        }
        update(a, b, x, 2*k+1, l, (l+r)/2);
        update(a, b, x, 2*k+2, (l+r)/2, r);
    }

    // 実質a+1=bであるが、幅1の区間和とみなしてシグネチャを区間和のものと統一する
    int query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(b <= l || r <= a)    return -1;
        eval(k, l, r);
        if(a <= l && r <= b)    return dat[k];
        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return max(lx, rx);
    }
};

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n, 2147483647);
    STlazy st(v);

    int a, b, c, d;
    while(q-- > 0){
        cin >> a >> b;
        if(a == 0){
            cin >> c >> d;
            st.update(b, c+1, d);
        }else{
            cout << st.query(b, b+1) << endl;
        }
        // for(int x : st.dat) cout << x << " ";
        // cout << endl;
        // for(int x : st.lazy) cout << x << " ";
        // cout << endl;
    }

    return 0;
}