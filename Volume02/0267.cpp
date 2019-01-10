#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<int> b;
        for(int i = 0; i < n; i++){
            int x;  cin>>x;
            b.push_back(x);
        }
        
        auto judge = [&]()->bool{
            if(b[0] != 1)   return false;
            for(int i = 1; i < b.size(); i++){
                if(b[i] != b[i-1]+1)    return false;
            }
            return true;
        };

        int ans = 0;
        for(;ans <= 10000; ans++){
            if(judge())    break;
            vector<int> v;
            for(int i = 0; i < b.size(); i++){
                if(b[i] != 1)   v.push_back(b[i]-1);
            }
            v.push_back(b.size());
            b = v;
        }
        if(ans > 10000) cout << -1 << endl;
        else            cout << ans << endl;
    }
    return 0;
}