#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int cnt = 0, input;
        bool able = false;
        
        for(int i = 0; i < n; i++){
            cin >> input;
            if(input > 1)   able = true;
            if(input > 0)   cnt++;
        }
        
        if(able)    cout << cnt+1 << endl;
        else        cout << "NA" << endl;
    }
    return 0;
}
