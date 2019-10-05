#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n, m;
    map<int,int> ma;
    cin >> n >> m;
    for(int i = 0; i < n+m; i++){
        int a;  cin >> a;
        ma[a]++;
    }
    vector<int> a, b;
    for(auto p : ma){
        if(p.second == 2)  a.push_back(p.first);
        b.push_back(p.first);
    }
    cout << a.size() << " " << b.size() << endl;
    for(int x : a)  cout << x << endl;
    for(int x : b)  cout << x << endl;
    return 0;
}
