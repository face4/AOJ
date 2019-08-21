#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int fun(string s, string t){
    int n = s.length();
    stack<int> x;
    for(int i = 0; i < n; i++){
        if(s[i] == '[' || s[i] == ']')  continue;
        if(inRange(s[i], 'a', 'd')){
            x.push(t[s[i]-'a']-'0');
            continue;
        }
        int j = x.top(); x.pop();
        int k = x.top(); x.pop();
        if(s[i] == '+'){
            x.push(j|k);
        }else if(s[i] == '*'){
            x.push(j&k);
        }else if(s[i] == '^'){
            x.push(j^k);
        }
    }
    return x.top();
}

int main(){
    string s, p;
    while(cin >> s, s != "."){
        reverse(s.begin(), s.end());
        cin >> p;
        int h = fun(s, p);
        int cnt = 0;
        for(int i = 0; i <= 9999; i++){
            string t = to_string(i);
            while(t.size() < 4) t = "0" + t;
            if(fun(s, t) == h)    cnt++;
        }
        cout << h << " " << cnt << endl;
    }
    return 0;
}