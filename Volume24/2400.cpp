#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int n, solve, pena;
    int w[11] = {};

    void init(int i){
        n = i;
        solve = 0;
        pena = 0;
    }

    void submit(int p, int t, string judge){
        if(judge == "CORRECT"){
            solve++;
            pena += w[p]*1200+t;
        }else if(judge == "WRONG"){
            w[p]++;
        }
    }

    bool operator< (const data other) const{
        if(solve != other.solve)    return solve > other.solve;
        if(pena != other.pena)      return pena < other.pena;
        return n < other.n;
    }

    void print(){
        cout << n << " " << solve << " " << pena << endl;
    }
};

int main(){
    int t, p, r;
    while(cin >> t >> p >> r, t+p+r){
        vector<data> v(t);
        for(int i = 0; i < t; i++)  v[i].init(i+1);

        int a, b, c;
        string s;

        for(int i = 0; i < r; i++){
            cin >> a >> b >> c >> s;
            v[--a].submit(b, c, s);
        }

        sort(v.begin(), v.end());

        for(data d : v) d.print();
    }
    return 0;
}