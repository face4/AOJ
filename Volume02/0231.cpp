#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        map<int, int> data;
        int m, a, b;

        for(int i = 0; i < n; i++){
            cin >> m >> a >> b;
            data[a] += m;
            data[b] -= m;
        }

        vector<pair<int,int>> v;
        for(map<int, int>::iterator it = data.begin(); it != data.end(); it++){
            v.push_back({*it});
        }

        sort(v.begin(), v.end());

        int accum = 0;
        bool broken = false;

        for(int i = 0; i < v.size(); i++){
            accum += v[i].second;
            if(accum > 150){
                broken = true;
            }
        }

        if(broken){
            cout << "NG" << endl;
        }else{
            cout << "OK" << endl;
        }
    }
    return 0;
}