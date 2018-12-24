#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;

    string c;
    int d;
    map<string, set<int>> ma;

    for(int i = 0; i < n; i++){
        cin >> c >> d;
        ma[c].insert(d);
    }

    int m;
    cin >> m;

    int now = 0;
    for(int i = 0; i < m; i++){
        cin >> c;
        auto it = ma[c].upper_bound(now);
        if(it == ma[c].end()){
            cout << "No" << endl;
            return 0;
        }
        now = *it;
        ma[c].erase(it);
    }

    cout << "Yes" << endl;

    return 0;
}