#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<pair<int,int>> v;
        int a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            v.push_back({b, a});
        }
        sort(v.begin(), v.end());
        int sum = 0;
        bool judge = true;
        for(int i = 0; i < n; i++){
            sum += v[i].second;
            if(sum > v[i].first)   judge = false;
        }

        if(judge)   cout << "Yes" << endl;
        else        cout << "No" << endl;
    }
    return 0;
}