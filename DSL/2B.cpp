#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

struct BIT{
    // 1-origin
    vector<int> v;
    int n;

    BIT(int _n):
        v(vector<int>(_n+1, 0)), n(_n) {}

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += v[i];
            i -= lsb(i);
        }
        return s;
    }

    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void add(int i, int x){
        while(i <= n){
            v[i] += x;
            i += lsb(i);
        }
    }

    ll invNum(){
        ll ret = 0;
        for(int j = 0; j < n; j++){
            ret += j - sum(v[j]);
            add(v[j], 1);
        }
        return ret;
    }

private:
    // least significant bit
    int lsb(int i){
        return i & -i;
    }
};


int main(){
    int n, q;
    cin >> n >> q;

    BIT b(n);
    int op, x, y;
    for(int i = 0; i < q; i++){
        cin >> op >> x >> y;
        if(op == 0){
            b.add(x, y);
        }else if(op == 1){
            cout << b.sum(x, y) << endl;
        }
    }

    return 0;
}

