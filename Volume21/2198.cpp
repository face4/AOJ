#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    string l;
    double s;
    data(string l, double s) : l(l), s(s) {}
    bool operator<(const data other) const{
        if(s == other.s){
            return l < other.l;
        }else{
            return s > other.s;
        } 
    }
};

int main(){
    int n;
    while(cin >> n, n){
        vector<data> v;
        string l;
        int p, a, b, c, d, e, f, s, m;
        for(int i = 0; i < n; i++){
            cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
            v.push_back(data(l, (double)(f*s*m-p)/(a+b+c+m*(d+e))));
        }
        sort(v.begin(), v.end());
        for(data d : v) cout << d.l << endl;
        cout << "#" << endl;
    }
    return 0;
}