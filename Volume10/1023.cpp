#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    int a, b, r;
    while(cin >> a >> b >> r, a+b){
        vector<double> ax[10050];
        for(int i = 0; i < a; i++){
            int x, y;
            cin >> x >> y;
            ax[x].push_back(y);
        }
        for(int i = 0; i < 10050; i++){
            if(ax[i].size())    sort(ax[i].begin(),ax[i].end());
        }
        ll ans = 0;
        for(int i = 0; i < b; i++){
            int x, y;
            cin >> x >> y;
            for(int j = -4*r; j <= 4*r; j++){
                if(x+j < 0) continue; 
                double rr = sqrt(4*r*4*r-j*j);
                ans += upper_bound(ax[x+j].begin(), ax[x+j].end(), y+rr)-lower_bound(ax[x+j].begin(),ax[x+j].end(),y-rr);
            }
        }
        cout << ans << endl;
    }
    return 0;
}