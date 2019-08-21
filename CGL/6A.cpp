#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

struct STsum{
private:
    int n;
    vector<int> dat;
public:
    STsum(int siz){
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, 0);
    }

    void update(int x, int val){
        x += (n-1);
        dat[x] += val;
        while(x > 0){
            x = (x-1)/2;
            dat[x] = dat[2*x+1]+dat[2*x+2];
        }
    }
    
    // focus on k-th node, who controls [l, r)
    int query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return dat[k];

        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> xax, ax(n), ay(n), bx(n), by(n);
    for(int i = 0; i < n; i++){
        cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
        xax.push_back(ax[i]);  xax.push_back(bx[i]);
    }
    sort(xax.begin(), xax.end());
    xax.erase(unique(xax.begin(),xax.end()),xax.end());
    auto f = [&](int val)->int{
        return lower_bound(xax.begin(),xax.end(),val)-xax.begin();
    };

    STsum seg(xax.size()+1);
    vector<pair<pair<int,int>, int>> vp;
    for(int i = 0; i < n; i++){
        if(ax[i] == bx[i]){
            vp.push_back({{min(ay[i],by[i]), 0}, i});
            vp.push_back({{max(ay[i],by[i]), 2}, i});
        }else if(ay[i] == by[i]){
            vp.push_back({{ay[i], 1}, i});
        }
    }
    sort(vp.begin(), vp.end());
    int ans = 0;
    for(auto p : vp){
        if(p.first.second == 0){
            seg.update(f(ax[p.second]), 1);
        }else if(p.first.second == 2){
            seg.update(f(ax[p.second]), -1);
        }else if(p.first.second == 1){
            ans += seg.query(f(min(ax[p.second],bx[p.second])), f(max(ax[p.second],bx[p.second]))+1);
        }
    }
    cout << ans << endl;

    return 0;
}