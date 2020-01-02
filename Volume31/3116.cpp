#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(),v.end());
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l) << endl;
    }
    return 0;
}
