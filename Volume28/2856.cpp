#include<iostream>
using namespace std;

int main(){
    int n, h, w, x, l;
    cin >> n >> h >> w;
    int imos[11000] = {}, b = 100;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(i%2) l = i*w-x;
        else    l = i*w+x;
        imos[b+l]++;
        imos[b+l+w]--;
    }
    for(int i = 1; i < 11000; i++)  imos[i] += imos[i-1];
    int ans = 0;
    for(int i = b; i < b+n*w; i++)  ans += (imos[i] <= 0);
    cout << ans*h << endl;
    return 0;
}