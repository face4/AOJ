#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int b[6][2] = { {0,1}, {0,1}, {0,2}, {0,2}, {1,2}, {1,2} };

int main(){
    vector<pair<int,int>> v;
    int x, y;

    for(int i = 0; i < 6; i++){
        cin >> x >> y;
        if(x > y)   swap(x, y);
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    bool judge = true;
    int a[3] = {v[0].first, v[0].second, v[2].second};
    
    for(int i = 0; i < 6; i++){
        judge &= v[i].first == a[b[i][0]];
        judge &= v[i].second == a[b[i][1]];
    }

    if(judge)   cout << "yes" << endl;
    else        cout << "no" << endl;

    return 0;
}