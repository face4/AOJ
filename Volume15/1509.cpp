#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, e, na, nb, nc;
    while(cin >> a >> b >> c >> d >> e, a+b+c+d+e){
        cin >> na >> nb >> nc;
        int ans = nc*c + nb*b + na*a;
        if(nc >= d){
            ans = min(ans, nc*e + nb*b + na*a);
        }else if(nc + nb >= d){
            ans = min(ans, d*e + b*(nb-(d-nc)) + na*a);
        }else if(nc + nb + na >= d){
            ans = min(ans, d*e + a*(na-(d-nc-nb)));
        }else if(nc*c+nb*b+na*a > d*e){
            ans = d*e;
        }
        cout << ans << endl;
    }
    return 0;
}