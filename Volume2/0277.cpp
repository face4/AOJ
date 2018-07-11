#include<iostream>
using namespace std;

int main(){
    int t, n;
    int p[4] = {6000, 4000, 3000, 2000};
    for(int i = 0; i < 4; i++){
        cin >> t >> n;
        cout << p[t-1]*n << endl;
    }
    return 0;
}
