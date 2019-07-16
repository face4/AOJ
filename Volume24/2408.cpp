#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n), bad(n, 0);
    for(int i = 0; i < k; i++){
        int m;  cin >> m;
        while(m-- > 0){
            int x;  cin >> x;
            v[--x] = i;
        }
    }
    int r;  cin >> r;
    while(r-- > 0){
        int p, q;
        cin >> p >> q;
        if(v[--p]==v[--q])  bad[p] = bad[q] = 1;
    }
    cout << accumulate(bad.begin(), bad.end(), 0) << endl;
    return 0;
}