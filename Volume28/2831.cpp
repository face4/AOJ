#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int i;
    for(i = 1; i < n; i++)  if(s[i] == 'x' && s[i-1] == 'x')    break;
    cout << i << endl;
    return 0;
}