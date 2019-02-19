#include<iostream>
#include<vector>
using namespace std;

const int INF = 2147483647;

struct STlazy{
private:
    int n;
    vector<int> node, lazy;

public:
    STlazy(){
        n = (1<<17)-1;
        node.resize(2*n-1, INF);
        lazy.resize(2*n-1, -1);
    }

    void eval(int k, int l, int r){
        if(lazy[k] == -1)   return;
        node[k] = lazy[k];
        if(r-l > 1) lazy[2*k+1] = lazy[2*k+2] = lazy[k];
        lazy[k] = -1;
    }

    void update(int a, int b, int val, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(b <= l || r <= a)    return;
        if(a <= l && r <= b){
            lazy[k] = val;
            eval(k, l, r);
            return;
        }
        update(a, b, val, 2*k+1, l, (l+r)/2);
        update(a, b, val, 2*k+2, (l+r)/2, r);
        node[k] = min(node[2*k+1], node[2*k+2]);
    }

    int query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(b <= l || r <= a)    return INF;
        eval(k, l, r);
        if(a <= l && r <= b)    return node[k];
        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return min(lx, rx);
    }
};

int main(){
    int n, q;
    cin >> n >> q;

    STlazy st;

    while(q-- > 0){
        int a, b, c, d;
        cin >> a >> b >> c;
        if(a == 0){
            cin >> d;
            st.update(b, c+1, d);
        }else{
            cout << st.query(b, c+1) << endl;
        }
    }
    return 0;
}