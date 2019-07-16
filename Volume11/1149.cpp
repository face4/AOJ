#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, w, d;
    while(cin >> n >> w >> d, n+w+d){
        vector<pair<int,int>> v;
        v.push_back({w,d});
        int p, s;
        while(n-- > 0){
            cin >> p >> s;
            p--;
            pair<int,int> c = v[p];
            w = c.first, d = c.second;
            v.erase(v.begin()+p);
            int i, j, k, l;
            s %= (w+d+w+d);
            if(s < w)           i = s, j = d, k = w-s, l = d;
            else if(s < w+d)    i = w, j = w+d-s, k = w, l = s-w;
            else if(s < w+d+w)  i = w+d+w-s, j = d, k = s-(w+d), l = d;
            else                i = w, j = w+d+w+d-s, k = w, l = s-(w+d+w);
            if(i*j > k*l)   swap(i, k), swap(j, l);
            v.push_back({i,j});
            v.push_back({k,l});
        }
        vector<int> ans;
        for(int i = 0; i < v.size(); i++)   ans.push_back(v[i].first*v[i].second);
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " \n"[i+1==ans.size()];
        }
    }
    return 0;
}