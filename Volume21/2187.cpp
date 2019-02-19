#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int t;  cin >> t;
    while(t-- > 0){
        vector<int> a(9), b(9);
        for(int i = 0; i < 9; i++)  cin >> a[i];
        for(int i = 0; i < 9; i++)  cin >> b[i];
        sort(b.begin(), b.end());
        int g = 0;
        do{
            int tmpg = 0;
            for(int i = 0; i < 9; i++)  if(a[i] > b[i]) tmpg += a[i]+b[i];
            if(tmpg > 85)   g++;
        }while(next_permutation(b.begin(), b.end()));
        double s = (double)g /1/2/3/4/5/6/7/8/9;
        cout << fixed << setprecision(5) << s << " " << 1-s << endl;
    }
    return 0;
}