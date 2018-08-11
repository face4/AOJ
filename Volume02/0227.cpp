#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    while(1){
        int n, m;
        cin >> n >> m;
        if(n + m == 0)  break;
        
        vector<int> p(n);
        for(int i = 0; i < n; i++)  cin >> p[i];
        sort(p.begin(), p.end());
        
        for(int i = n-m; i >= 0; i -= m){
            p[i] = 0;
        }
        
        cout << accumulate(p.begin(), p.end(), 0) << endl;
    }
    return 0;
}
