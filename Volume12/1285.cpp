#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(){
    int n, w, x;
    while(cin >> n >> w, n+w){
        int hist[11] = {};
        for(int i = 0; i < n; i++){
            cin >> x;
            hist[x/w]++;
        }
        int ma = *max_element(hist, hist+11);
        int width;
        for(width = 10;; width--)   if(hist[width]) break;
        double ink = 0.01;
        for(int i = 0; i <= width; i++){
            ink += (double)hist[i] / ma * (width-i) / width;
        }
        cout << fixed << setprecision(10) << ink << endl;
    }
    return 0;
}