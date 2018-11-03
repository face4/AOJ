#include<iostream>
#include<map>
#include<vector>
using namespace std;

int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int mdtod(int m, int d){
    int accum = 0;
    for(int i = 0; i < m-1; i++)    accum += month[i];
    accum += d;
    return accum;
}

int main(){
    int n;
    while(scanf("%d\n", &n), n){
        map<int, vector<int>> record;

        int M, D, h, m, p;
        char e;

        for(int i = 0; i < n; i++){
            scanf("%d/%d %d:%d %c %d\n", &M, &D, &h, &m, &e, &p);
            record[p].push_back(mdtod(M, D)*1440 + 60*h + m);
        }

        int ans = 0;
        for(auto x : record){
            if(x.first == 0)    continue;
            int tmp = 0;
            for(int i = 0; i < x.second.size(); i+=2){
                for(int j = 0; j < record[0].size(); j+=2){
                    tmp += max(0, min(x.second[i+1],record[0][j+1])-max(x.second[i],record[0][j]));
                }
            }
            ans = max(ans, tmp);
        }

        cout << ans << endl;
    }
    return 0;
}