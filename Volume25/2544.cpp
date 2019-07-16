#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int i;  string s;
    bool operator<(const data other) const{
        return i < other.i;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<data> vp;
    vp.push_back({0, "kogakubu10gokan"});
    for(int i = 0; i< n; i++){
        int k;  string s;
        cin >> k >> s;
        vp.push_back(data({k,s}));
    }
    cout << (*(--upper_bound(vp.begin(), vp.end(),data({q, ""})))).s << endl;
    return 0;
}