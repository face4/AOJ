#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const int INF = 1<<30;

struct STmax{
private:
    int n;
    vector<ll> dat;
public:
    STmax(int siz){
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, 0);
    }

    void update(int x, ll val){
        x += (n-1);
        dat[x] = val;
        while(x > 0){
            x = (x-1)/2;
            dat[x] = max(dat[2*x+1], dat[2*x+2]);
        }
    }
    
    // focus on k-th node, who controls [l, r)
    ll query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return dat[k];

        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return max(lx, rx);
    }
};

int main(){
    int n;
    cin >> n;
    STmax seg(n+1);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        seg.update(x, seg.query(0, x)+x);
    }
    cout << (ll)n*(n+1)/2-seg.query(0, n+1) << endl;
}