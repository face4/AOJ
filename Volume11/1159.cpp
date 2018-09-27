#include<iostream>
using namespace std;

int main(){
    int n, p;
    while(cin >> n >> p, n+p){
        int a[50] = {}, wan = p, step = 0;
        while(1){
            if(wan > 0) wan--, a[step%n]++;
            else if(a[step%n])  wan += a[step%n], a[step%n] = 0;
            if(a[step%n] == p)  break;
            step++;
        }
        cout << step%n << endl;
    }
    return 0;
}