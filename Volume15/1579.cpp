#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int n, a, d, m, k;
    cin >> n >> a >> d;
    cin >> m;
    vector<int> x(m), y(m), z(m);
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> z[i];
        y[i]--, z[i]--;
    }
    cin >> k;
    k--;
    for(int i = m-1; i >= 0; i--){
        if(x[i]==0&&inRange(k,y[i],z[i])){
            k = y[i] + z[i] - k;
        }
    }
    int ans = a+k*d;
    for(int i = 0; i < m; i++){
        if(!inRange(k, y[i], z[i])) continue;
        if(x[i] == 0){
            k = y[i] + z[i] - k;
        }else if(x[i] == 1){
            ans++;
        }else if(x[i] == 2){
            ans /= 2;
        }
    }
    cout << ans << endl;
    return 0;
}