#include<iostream>
using namespace std;

int main(){
    int z;
    while(cin >> z, z){
        z *= z*z;
        int ans = z;
        for(int i = 1; i*i*i <= z; i++){
            for(int j = i; j*j*j <= z-i*i*i; j++){
                ans = min(ans, z-i*i*i-j*j*j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}