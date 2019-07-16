#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<string> stat(n), a(n), b(n);
        for(int i = 0; i < n; i++)  cin >> stat[i] >> a[i] >> b[i];
        vector<string> ans;
        while(m-- > 0){
            string x, y, z;
            cin >> x >> y >> z;
            int rule = -1;
            for(int i = 0; i < n; i++){
                bool match = true;
                for(int j = 0; j < 8; j++)  match &= (a[i][j]=='?'||a[i][j]==x[j]);
                for(int j = 0; j < 8; j++)  match &= (b[i][j]=='?'||b[i][j]==y[j]);
                if(match)   rule = i;
            }
            bool permit = false;
            if(rule != -1 && stat[rule] == "permit")    permit = true;
            if(permit){
                stringstream ss;
                ss << x << " " << y << " " << z;
                ans.push_back(ss.str());
            }
        }
        cout << ans.size() << endl;
        for(string s : ans) cout << s << endl;
    }
    return 0;
}
