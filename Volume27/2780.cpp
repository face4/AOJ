#include<iostream>
using namespace std;

bool ok(string s){
    char x = s[0];
    for(int i = 1; i < s.length(); i++){
        x++;
        if(s[i] != x)   return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int ans = -1;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(ok(to_string(a[i]*a[j])))    ans = max(ans, a[i]*a[j]);
        }
    }

    cout << ans << endl;
    
    return 0;
}