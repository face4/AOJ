#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<int> a(m+1, 0), b(m+1, 0), c(m+1, 0);
        while(n-- > 0){
            string s;
            int w, x, y, z;
            getline(cin, s);
            getline(cin, s);
            cin >> w >> x >> y >> z;
            for(int i = 0; i <= m-w; i++){
                a[i+w] = max(a[i+w], a[i]+x);
                b[i+w] = max(b[i+w], b[i]+y);
                c[i+w] = max(c[i+w], c[i]+z);
            }
        }
        cout << max( {*max_element(a.begin(), a.end()), 
                      *max_element(b.begin(), b.end()),
                      *max_element(c.begin(), c.end())} ) << endl;
    }
    return 0;
}