#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<double> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    
    vector<double> s = v;
    sort(s.begin(), s.end());
    
    for(double i : v){
        auto l = lower_bound(s.begin(), s.end(), i);
        auto r = upper_bound(s.begin(), s.end(), i);
        cout << 3*(l-s.begin()) + (r-l-1) << endl;
    }

    return 0;
}