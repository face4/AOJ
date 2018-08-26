#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> res;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        res.push_back(max(0, n-a));
    }

    sort(res.begin(), res.end());

    cout << accumulate(res.begin(), res.end(), 0) - res[m-1] << endl;

    return 0;
}