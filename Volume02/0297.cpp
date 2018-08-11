#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    while(n--){
        int k, p;
        cin >> k >> p;
        if(k%p) cout << k%p << endl;
        else    cout << p << endl;
    }

    return 0;
}
