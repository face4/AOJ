#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        string res = "";
        while(n != 0){
            int x = n%10;
            if(x < 0)   x += 10;            
            res = (char)('0'+x) + res;
            if(n < 0 && n%10 != 0)  while(n%10 != 0)    n--;
            n /= -10;
        }
        cout << res << endl;
    }
    return 0;
}