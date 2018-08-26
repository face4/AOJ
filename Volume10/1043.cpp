#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct data{
    int i, u, a, p;
    data(int _i, int _u, int _a, int _p) : i(_i), u(_u), a(_a), p(_p) {}
    bool operator<(const data other) const{
        if(a != other.a)      return a > other.a;
        else if(p != other.p) return p < other.p;
        else                  return i < other.i;               
    }
};

int main(){
    int n;
    while(cin >> n, n){
        int i, u, a, p;
        vector<data> v;
        
        for(int t = 0; t < n; t++){
            cin >> i >> u >> a >> p;
            v.push_back(data(i,u,a,p));
        }
        
        sort(v.begin(), v.end());
        
        int uni[1001] = {};
        int passed = 0;

        for(data x : v){
            bool rulea = passed < 10 && uni[x.u] < 3;
            bool ruleb = passed < 20 && uni[x.u] < 2;
            bool rulec = passed < 26 && uni[x.u] < 1;
            if(rulea || ruleb || rulec){
                cout << x.i << endl;
                uni[x.u]++;
                passed++;
            }
        }

    }
    return 0;
}