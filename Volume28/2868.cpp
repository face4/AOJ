#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    vector<int> pos[5];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[2+a[i]].push_back(i);
    }
    vector<int> use;
    for(int i = 0; i + 1 < pos[0].size(); i+=2){
        use.push_back(pos[0][i]);
        use.push_back(pos[0][i+1]);
    }
    if(pos[0].size()%2 && pos[1].size()){
        use.push_back(pos[0][pos[0].size()-1]);
        use.push_back(pos[1][0]);
    }
    for(int i = 0; i < pos[4].size(); i++){
        use.push_back(pos[4][i]);
    }

    sort(use.begin(), use.end());
    cout << use.size() << endl;
    for(int x : use)    cout << x+1 << endl;
    return 0;
}