#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t-- > 0){
        int a[9];
        for(int i = 0; i < 9; i++)  cin >> a[i];
        char x;
        for(int i = 0; i < 9; i++){
            cin >> x;
            if(x == 'G')    a[i] += 20;
            if(x == 'B')    a[i] += 40;
        }

        int b[50] = {};
        for(int i = 0; i < 9; i++)  b[a[i]]++;

        bool judge = true;
        for(int i = 0; i < 50; i++){
            if(b[i] == 0)   continue;
            if(b[i] >= 3)   b[i] -= 3;
            while(b[i] && b[i+1] && b[i+2]){
                b[i]--, b[i+1]--, b[i+2]--;
            }
            if(b[i])    judge = false;
        }

        cout << judge << endl;
    }
    return 0;
}