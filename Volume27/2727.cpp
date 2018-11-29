#include<iostream>
using namespace std;

string s;

bool judge(string a, string b){
    int n = a.length();

    for(int i = 0; i < n; i++){
        int cur = 0, posi = i, posj = 0;
        while(cur < n){
            while(posi < n && a[posi] != s[cur])    posi++;
            if(posi == n)   break;
            posi++, cur++;
            if(cur == n)    return true;
            while(posj < n && b[posj] != s[cur])    posj++;
            if(posj == n)   break;
            posj++, cur++;
            if(cur == n)    return true;
        }
    }

    return false;
}

int main(){
    string t;
    cin >> s >> t;

    cout << ( (judge(s,t) || judge(t,s)) ? "Yes" : "No") << endl;

    return 0;
}