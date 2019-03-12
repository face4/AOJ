#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, a[26] = {}, b[26] = {};
    cin >> n;
    char c;
    for(int i = 0; i < n; i++)  cin >> c, a[c-'a']++;
    for(int i = 0; i < n; i++)  cin >> c, b[c-'a']++;
    sort(a, a+26);
    sort(b, b+26);
    int ret = 0;
    for(int i = 0; i < 26; i++) ret += abs(a[i]-b[i]);
    cout << ret/2 << endl;
    return 0;
}