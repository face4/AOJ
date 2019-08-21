#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double maxd[2] = {-1, -1};
    double tim[2] = {-1, -1};
    int t, a, f, x, y;
    cin >> t >> a >> f >> x >> y;
    for(int i = 1; i < n; i++){
        int nf, na, nt, nx, ny;
        cin >> nt >> na >> nf >> nx >> ny;
        if(f == nf && a != na){
            double d = sqrt(pow(nx-x,2.0)+pow(ny-y,2.0));
            if(maxd[f] < d || (maxd[f]==d && (nt-t)/60.0 < tim[f])){
                maxd[f] = d;
                tim[f] = (nt-t)/60.0;
            }
        }
        f = nf, a = na, t = nt, x = nx, y = ny;
    }
    for(int i = 0; i < 2; i++){
        cout << fixed << setprecision(12) << maxd[i] << " " << tim[i] << endl;
    }
    return 0;
}