#include<iostream>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        
        if(n == 0)  break;
        
        int A[n];
        for(int i = 0; i < n; i++)  cin >> A[i];

        int rest = 32;
        bool ichiro = true;
        int pos = 0;

        while(rest != 0){
            if(ichiro){
                rest -= (rest-1)%5;
            }else{
                rest -= A[pos];
                pos = (pos+1)%n;
            }

            ichiro = !ichiro;
            if(rest < 0)    rest = 0;
            cout << rest << endl;
        }
    }

    return 0;
}