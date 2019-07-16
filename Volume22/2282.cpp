#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct data{
    int h, t, i;
    bool operator<(const data other) const{
        if(t != other.t)    return t < other.t;
        else                return h < other.h;
    }
};

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        int h[n], t[n];
        for(int i = 0; i < n; i++)  cin >> h[i];
        t[0] = m/h[0]*h[0];
        priority_queue<data> pq;
        pq.push(data({h[0], t[0], 0}));
        for(int i = 1; i < n; i++){
            int upper = pq.top().t;
            int want = (upper + h[i] - 1)*h[i];
            if(want > m){
                want = m/h[i]*h[i];
            }else if(want == upper && pq.top().h == h[i]){
                want += h[i];
                if(want > m)    want -= h[i];
            }
            t[i] = want;
            pq.push(data({h[i], t[i], i}));
        }
        vector<data> v;
        while(!pq.empty())  v.push_back(pq.top()), pq.pop();

        data d = v[n-1];
        data e = v[n-2];

        if(d.t == e.t){
            if(d.h == e.h)  cout << n << endl;
            else            cout << d.i+1 << endl;
        }else{
            cout << d.i+1 << endl;
        }
    }
    return 0;
}
