#include<iostream>
#include<algorithm>
using namespace std;

bool check(char x, char y){
    if(x > y)   swap(x, y);
    return (x=='('&&y==')') || (x=='{'&&y=='}') || (x=='['&&y==']');
}

int main(){
    string s;   cin >> s;
    int x = s.find('i');
    string a = s.substr(0, x), b = s.substr(x+3);
    reverse(a.begin(), a.end());
    if(a.length() > b.length()) swap(a,b);
    int ans = 0;
    for(int i = 1; i < 1<<(a.length()); i++){
        string t = "";
        for(int j = 0; j < a.length(); j++) if((i>>j)&1)    t += a.substr(j,1);
        int cur = 0;
        for(int j = 0; cur < t.length() && j < b.length(); j++){
            if(check(t[cur], b[j]))  cur++;
        }
        if(cur == t.length())   ans = max(ans, cur);
    }
    cout << 2*ans+3 << endl;
    return 0;
}