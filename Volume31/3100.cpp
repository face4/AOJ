#include<iostream>
using namespace std;

int main(){
    int x, a, b;
    int n;
    cin >> x >> a >> b >> n;
    for(int i = 0; i < n; i++){
        string s;   cin >> s;
        if(s[0] == 'n') x += a;
        if(s[0] == 't') x += b;
        if(s[0] == 'k') x = 0;
        x = max(x, 0);
    }
    cout << x << endl;
    return 0;
}
