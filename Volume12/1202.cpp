#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, cnt = 1;
    while(cin >> n, n){
        vector<double> x(n), y(n), r(n), xax, yax;
        xax.push_back(-300.0); yax.push_back(-300.0);
        xax.push_back(300.0);  yax.push_back(300.0);
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> r[i];
            xax.push_back(x[i]-r[i]); xax.push_back(x[i]+r[i]);
            yax.push_back(y[i]-r[i]); yax.push_back(y[i]+r[i]);
        }
        sort(xax.begin(), xax.end());
        sort(yax.begin(), yax.end());
        xax.erase(unique(xax.begin(),xax.end()), xax.end());
        yax.erase(unique(yax.begin(),yax.end()), yax.end());
        int xn = xax.size(), yn = yax.size();
        auto fx = [&](double val)->int{
            return lower_bound(xax.begin(), xax.end(), val)-xax.begin();
        };
        auto fy = [&](double val)->int{
            return lower_bound(yax.begin(), yax.end(), val)-yax.begin();
        };
        vector<vector<int>> v(xn, vector<int>(yn, 0));
        for(int i = 0; i < n; i++){
            int a = fx(x[i]-r[i]), b = fx(x[i]+r[i]), c = fy(y[i]-r[i]), d = fy(y[i]+r[i]);
            v[a][c]++, v[b][d]++;
            v[a][d]--, v[b][c]--;
        }
        for(int i = 0; i < xn; i++) for(int j = 1; j < yn; j++) v[i][j] += v[i][j-1];
        for(int j = 0; j < yn; j++) for(int i = 1; i < xn; i++) v[i][j] += v[i-1][j];
        double s = 0;
        for(int i = 0; i < xn; i++){
            for(int j = 0; j < yn; j++){
                if(v[i][j] == 0)    continue;
                s += (xax[i+1]-xax[i])*(yax[j+1]-yax[j]);
            }
        }
        printf("%d %.2f\n", cnt++, ((int)(s*100))/100.0);
    }
    return 0;
}