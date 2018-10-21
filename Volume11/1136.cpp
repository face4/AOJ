#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> vi;

void rotate(vi& x, vi& y){
    for(int i = 0; i < x.size(); i++){
        swap(x[i], y[i]);
        y[i] *= -1;
    }
}

bool same(vi ax, vi ay, vi bx, vi by){
    for(int i = 0; i < ax.size(); i++){
        if(ax[i] != bx[i])  return false;
        if(ay[i] != by[i])  return false;
    }
    return true;
}

int main(){
    int n, x[10], y[10];

    while(cin >> n, n){
        int t;
        cin >> t;

        for(int i = 0; i < t; i++)  cin >> x[i] >> y[i];

        vi tx, ty;
        for(int i = 1; i < t; i++){
            tx.push_back(x[i]-x[i-1]);
            ty.push_back(y[i]-y[i-1]);
        }

        int m;
        for(int i = 1; i <= n; i++){
            cin >> m;
            for(int j = 0; j < m; j++)  cin >> x[j] >> y[j];
            if(m != t)  continue;

            vi nx, ny;
            for(int j = 1; j < m; j++){
                nx.push_back(x[j]-x[j-1]);
                ny.push_back(y[j]-y[j-1]);
            }

            bool judge = false;
            for(int i = 0; i < 4; i++){
                if(same(tx, ty, nx, ny))    judge = true;
                rotate(nx, ny);
            }
            reverse(nx.begin(), nx.end());
            reverse(ny.begin(), ny.end());
            for(int i = 0; i < 4; i++){
                if(same(tx, ty, nx, ny))    judge = true;
                rotate(nx, ny);
            }

            if(judge) cout << i << endl;
        }

        cout << "+++++" << endl;
    }
    return 0;
}