#include<iostream>
using namespace std;

bool contains(string str, string pre){
    int s = str.length(), p = pre.length();
    if(s < p)   return false;

    for(int i = 0; i <= s - p; i++){
        int j;
        for(j = 0; j < p; j++){ 
            if(str[i+j] != pre[j])  break;
        }
        if(j == p)  return true;
    }

    return false;
}

int main(){
    string s;
    cin >> s;

    int n;
    cin >> n;

    int ans = 0;
    string t;
    for(int i = 0; i < n; i++){
        cin >> t;
        t += t;
        if(contains(t,s))   ans++;
    }

    cout << ans << endl;
    return 0;
}