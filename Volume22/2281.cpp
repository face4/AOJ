#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        string s;
        cin >> s;
        int a[n], b[n];
        for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];
        for(int i = n-1; i >= 0; i--){
            int c = abs(a[i]-b[i]);
            s[a[i]-1] = (char)('a' + (s[a[i]-1]-'a'+c)%26);
            s[b[i]-1] = (char)('a' + (s[b[i]-1]-'a'+c)%26);
            swap(s[a[i]-1], s[b[i]-1]);
        }
        cout << s << endl;
    }

}
