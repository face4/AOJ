#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

class STlazy{
private:
    int n;
    vector<int> node, lazy;

public:
    STlazy(vector<int> v){
        int siz = v.size();
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 1);
        
        for(int i = 0; i < siz; i++)    node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = node[2*i+1] + node[2*i+2];
    }

    void eval(int k, int l, int r){
        if(lazy[k] == 1)    return;
        node[k] *= lazy[k];
        if(r-l > 1){
            lazy[2*k+1] *= lazy[k];
            lazy[2*k+2] *= lazy[k];
        }
        lazy[k] = 1;
    }

    void update(int a, int b, int x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(r <= a || b <= l)    return;
        if(a <= l && r <= b){
            lazy[k] *= x;
            eval(k, l, r);
            return;
        }
        update(a, b, x, 2*k+1, l, (l+r)/2);
        update(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2]; // 自分の全ての子孫の値伝播が終わったら自分を更新する
    }

    int query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r); // 最初の呼び出しが必ずeval(0,0,n)となるので漏れなく上から値の伝播がなされている
        if(a <= l && r <= b)    return node[k];
        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

vector<int> child[100000], euler, l(100000), r(100000);

void euler_tour(int parent, int current, int &cnt){
    l[current] = cnt++;
    for(int i = 0; i < child[current].size(); i++){
        if(child[current][i] != parent) euler_tour(current, child[current][i], cnt);
    }
    r[current] = cnt++;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int x;  cin >> x;
        child[--x].push_back(i);
    }
    int cnt = 0;
    euler_tour(-1, 0, cnt);
    euler.resize(cnt);

    for(int i = 0; i < n; i++){
        char c; cin >> c;
        euler[l[i]] = euler[r[i]] = (c=='G')*2-1;
    }

    STlazy seg(euler);
    
    while(q-- > 0){
        int t;  cin >> t;
        t--;
        seg.update(l[t], r[t]+1, -1);
        cout << (seg.query(0, cnt+1) > 0 ? "broccoli" : "cauliflower") << endl;
    }
    return 0;
}