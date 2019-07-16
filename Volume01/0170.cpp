#include<iostream>
#include<vector>
#include<algorithm>
#include<cfloat>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<string> f(n);
        vector<int> w(n), s(n), a(n);
        double wsum = 0;
        for(int i = 0; i < n; i++){
            cin >> f[i] >> w[i] >> s[i];
            a[i] = i;
            wsum += w[i];
        }
        vector<int> ans(n);
        double g = DBL_MAX;
        do{
            double accw = 0, tmpg = 0;
            bool valid = true;
            for(int i = 0; i < n; i++){
                if(s[a[i]] < accw){
                    valid = false;
                    break;
                }
                accw += w[a[i]];
                tmpg += (n-i)*w[a[i]];
            }
            if(valid && tmpg/wsum < g){
                g = tmpg/wsum;
                ans = a;
            }
        }while(next_permutation(a.begin(), a.end()));
        for(int i = n-1; i >= 0; i--){
            cout << f[ans[i]] << endl;
        }
    }
    return 0;
}