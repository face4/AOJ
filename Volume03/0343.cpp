#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

typedef pair<ll,int> pli;

struct BIT{
    vector<int> node;
    int n;

    BIT(int x) : n(x){
        node.resize(n+1, 0);
    }

    void add(int x, int val){
        while(x <= n){
            node[x] += val;
            x += x & -x;
        }
    }

    int sum(int x){
        int ret = 0;
        while(x > 0){
            ret += node[x];
            x -= x & -x;
        }
        return ret;
    }
};

int main(){
    int n, c;
    cin >> n >> c;
    vector<pli> vp;
    vector<ll> score(n, 0);
    for(int i = 0; i < n; i++)  vp.push_back({-score[i], i});
    vector<int> x(c), y(c), z(c);
    for(int i = 0; i < c; i++){
        cin >> x[i];
        if(x[i] == 0){
            cin >> y[i] >> z[i];
            y[i]--;
            score[y[i]] += z[i];
            vp.push_back({-score[y[i]], y[i]});
        }else{
            cin >> y[i];
        }
    }
    sort(vp.begin(), vp.end());
    auto f = [&](pli p)->int{
        return lower_bound(vp.begin(),vp.end(),p)-vp.begin();
    };
    int siz = vp.size();

    BIT bit(siz);
    for(int i = 0; i < n; i++){
        bit.add(1+f({-0,i}),1);
    }

    fill(score.begin(), score.end(), 0);

    for(int i = 0; i < c; i++){
        if(x[i] == 0){
            bit.add(1+f({-score[y[i]],y[i]}), -1);
            score[y[i]] += z[i];
            bit.add(1+f({-score[y[i]],y[i]}), 1);
        }else{
            int l = -1, r = siz;
            while(r-l > 1){
                int mid = (l+r)/2;
                if(bit.sum(1+mid) < y[i]) l = mid;
                else                    r = mid;
            }
            cout << vp[r].second+1 << " " << -vp[r].first << endl;
        }
    }
    return 0;
}