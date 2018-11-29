#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int b;
    while(cin >> b, b){
        int n;
        for(n = sqrt(2*b);; n--){
            if((b-n*(n-1)/2) % n == 0)  break;
        }
        cout << (b-n*(n-1)/2)/n << " " << n << endl;
    }
    return 0;
}