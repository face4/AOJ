#include<iostream>
#include<vector>
using namespace std;

// クエリは全て半開区間[a,b)
class STlazy{
private:
    int n;
    vector<int> node, lazy;

public:
    STlazy(){
        n = (1<<17)-1;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, -1001);
    }

    void eval(int k, int l, int r){
        if(lazy[k] == -1001)    return;
        node[k] = (r-l)*lazy[k];
        if(r-l > 1){
            lazy[2*k+1] = lazy[k];
            lazy[2*k+2] = lazy[k];
        }
        lazy[k] = -1001;
    }

    void update(int a, int b, int x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(r <= a || b <= l)    return;
        if(a <= l && r <= b){
            lazy[k] = x;
            eval(k, l, r);
            return;
        }
        update(a, b, x, 2*k+1, l, (l+r)/2);
        update(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2];
    }

    int query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r);
        if(a <= l && r <= b)    return node[k];
        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    int a, b, c, d;
    STlazy st;
    while(q-- > 0){
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