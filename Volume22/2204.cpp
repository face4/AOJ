#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int mi = 500, ma = 0;
        for(int i = 0; i < n; i++){
            int sum = 0, a;
            for(int j = 0; j < 5; j++){
                cin >> a;
                sum += a;
            }
            mi = min(mi, sum);
            ma = max(ma, sum);
        }
        cout << ma << " " << mi << endl;
    }
    return 0;
}