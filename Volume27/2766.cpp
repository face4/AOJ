#include<iostream>
using namespace std;

int main(){
    int n, d;
    string x, y = "";
    cin >> n >> x >> d;
    for(int i = 0; i < n; i++){
        if(d > 0){
            y += "1";
            if(x[i] == '0') d--;
        }else{
            y += x[i];
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(d != 0 && x[i] == y[i])  d--, y[i] = (char)('1'-y[i]+'0');
    }
    cout << y << endl;
    return 0;
}