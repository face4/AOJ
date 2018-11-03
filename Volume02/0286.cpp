#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n , &m);

    vector<pair<int,int>> v[m];

    int s, t, e;
    while(scanf("%d %d %d", &s, &t, &e), s+t+e){
        v[--t].push_back({--s,e});
    }

    int l;
    scanf("%d", &l);

    for(int i = 0; i < l; i++){
        vector<int> sal(n), b(m);
        for(int i = 0; i < m; i++)  scanf("%d", b.begin()+i);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < v[i].size(); j++){
                sal[v[i][j].first] += v[i][j].second * b[i];
            }
        }
        for(int i = 0; i < n; i++)  printf("%d%c", sal[i], " \n"[i == n-1]);
    }

    return 0;
}