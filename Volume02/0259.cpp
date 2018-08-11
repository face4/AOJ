#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, d[4];
    while(cin >> n){
        if(n == 0)  break;
        
        if(n % 1111 == 0){
            cout << "NA" << endl;
        }else{
            int tmpn = n;
            for(int i = 3; i >= 0; i--){
                d[i] = tmpn%10;
                tmpn /= 10;
            }
            
            int ans = 0;
            while(n != 6174){
                ans++;
                sort(d, d+4);
                n = (1000*d[3] + 100*d[2] + 10*d[1] + d[0]) -
                        (1000*d[0] + 100*d[1] + 10*d[2] + d[3]);
                tmpn = n;
                for(int i = 3; i >= 0; i--){
                    d[i] = tmpn%10;
                    tmpn /= 10;
                }
            }
            
            cout << ans << endl;
        }
    }
    return 0;
}
