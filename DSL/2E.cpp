#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

// クエリは全て半開区間[a,b)
class STlazy{
private:
    int n;
    vector<ll> node, lazy;

public:
    STlazy(vector<ll> v){
        // int siz = v.size();
        // n = 1;
        // while(n < siz)  n *= 2;
        n = 1<<17;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        
        // for(int i = 0; i < siz; i++)    node[n-1+i] = v[siz];
        // for(int i = n-2; i >= 0; i--)   node[i] = node[2*i+1] + node[2*2+2];
    }

    void eval(int k, int l, int r){
        if(lazy[k] == 0)    return;
        node[k] += lazy[k];
        if(r-l > 1){
            lazy[2*k+1] += lazy[k]/2;
            lazy[2*k+2] += lazy[k]/2;
        }
        lazy[k] = 0;
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(r <= a || b <= l)    return;
        if(a <= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2]; // 自分の全ての子孫の値伝播が終わったら自分を更新する
    }

    // find(i)を区間幅1の区間和に対するクエリとみなすので実質b=a+1
    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r); // 最初の呼び出しが必ずeval(0,0,n)となるので漏れなく上から値の伝播がなされている
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> v(n, 0);
    STlazy st(v);
    while(q-- > 0){
        int a, b, c, d;
        cin >> a >> b;
        if(a == 0){
            cin >> c >> d;
            st.add(b, c+1, d);
        }else{
            cout << st.query(b, b+1) << endl;
        }
    }
    return 0;
}