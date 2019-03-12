#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<bool> nonp(1000001, 0);
    for(int i = 2; i < 1000001; i++){
        if(nonp[i]) continue;
        for(int j = i+i; j < 1000001; j += i)   nonp[j] = true;
    }
    int a, b;
    while(cin >> a >> b, a+b){
        int x = 1<<30, y = 1<<30;
        for(int i = a; i >= 2; i--){
            if(a%i == 0 && !nonp[i]){
                if(x == 1<<30)  x = i;
                else            x -= i;
            }
        }
        for(int i = b; i >= 2; i--){
            if(b%i == 0 && !nonp[i]){
                if(y == 1<<30)  y = i;
                else            y -= i;
            }
        }
        cout << (x > y ? "a" : "b") << endl;
    }
    return 0;
}