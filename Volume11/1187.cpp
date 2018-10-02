#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int team, solve, tim;
    int pena[11] = {};
    data() {}
    data(int t) : team(t) {solve = 0, tim = 0;}
    void add(int p, int r){
        solve++;
        tim += r + pena[p]*20;
    }

    bool operator <(const data other) const{
        if(solve != other.solve){
            return solve > other.solve;
        }else if(tim != other.tim){
            return tim < other.tim;
        }else{
            return team > other.team;
        }
    }

    bool operator ==(const data other){
        return solve == other.solve && tim == other.tim;
    }
};

int main(){
    int M, T, P, R;

    while(cin >> M >> T >> P >> R, M+T+P+R){
        vector<data> v(T);
        for(int i = 0; i < T; i++)  v[i] = data(i+1);

        int m, t, p, j;
        for(int i = 0; i < R; i++){
            cin >> m >> t >> p >> j;
            if(j == 0){
                v[t-1].add(p, m);
            }else{
                v[t-1].pena[p]++;
            }
        }

        sort(v.begin(), v.end());

        cout << v[0].team;
        for(int i = 1; i < T; i++){
            if(v[i] == v[i-1])  cout << "=";
            else                cout << ",";
            cout << v[i].team;
        }
        cout << endl;
    }
    return 0;
}