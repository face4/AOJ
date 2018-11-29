#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin >> s;

    int a[4] = {};
    int face = 0;

    int ans = 0;
    bool right = false;
    for(char c : s){
        if(face == 0 && c == 'R')   right = true;
        else if(face == 0 && c == 'L')  right = false;
        if(c == 'R')    face = (face+1)%4;
        else            face = (face-1+4)%4;
        a[face]++;
        if(face == 0){
            if(c == 'R' && right && a[1] > 0 && a[2] > 0 && a[3] > 0)    ans++;
            memset(a, 0, sizeof(a));
        }
    }

    cout << ans << endl;

    return 0;
}