#include<iostream>
using namespace std;

int main(){
    int e;
    while(cin >> e, e){
        int ans = e;
        for(int z = 0; z*z*z <= e; z++){
            for(int y = 0; z*z*z+y*y <= e; y++){
                ans = min(ans, z+y+(e-z*z*z-y*y));
            }
        }
        cout << ans << endl;
    }
    return 0;
}