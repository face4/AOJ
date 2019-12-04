#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<int> pos(n), height(n, 0);
        for(int i = 0; i < n; i++)  pos[i] = i;
        vector<list<int>> v;
        for(int i = 0; i < n; i++){
            list<int> x{i};
            v.push_back(x);
        }
        int a, b;
        while(cin >> a >> b, a+b != 0){
            a--, b--;
            if(a == b)  continue;
            if(pos[a]==pos[b] && height[a] > height[b]) continue;
            if(b == -1 && height[a] == 0)   continue;

            while(v[pos[a]].back() != a){
                int take = v[pos[a]].back();    v[pos[a]].pop_back();
                list<int> x{take};
                v.push_back(x);
                pos[take] = v.size()-1;
                height[take] = 0;
            }

            // take a
            v[pos[a]].pop_back();
            if(b != -1){
                v[pos[b]].push_back(a);
                pos[a] = pos[b];
                height[a] = v[pos[a]].size()-1;
            }else{
                list<int> x{a};
                v.push_back(x);
                pos[a] = v.size()-1;
                height[a] = 0;
            }
        }
        vector<int> ans;
        for(list<int> x : v)    if(!x.empty())  ans.push_back(x.size());
        sort(ans.begin(), ans.end());
        for(int x : ans)    cout << x << endl;
        cout << "end" << endl;
    }
    return 0;
}