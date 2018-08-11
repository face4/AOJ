#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++)  cin >> p[i];
    sort(p.begin(), p.end());

    for(int i = p[n-1]; i >= 0; i--){
        int num = p.end() - lower_bound(p.begin(), p.end(), i);
        if(num >= i){
            cout << i << endl;
            return 0;
        }
    }
}