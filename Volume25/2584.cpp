#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    string s;
    while(cin >> s, s != "."){
        string t = "";
        int i = 0;
        while(i < s.length()){
            if(s[i] == '-' || s[i] == '+'){
                int cnt = 0;
                while(i < s.length() && (s[i] != '?' && !inRange(s[i], 'A', 'Z'))){
                    cnt += s[i++] == '-' ? -1 : 1;
                }
                if(s[i] == '?') t += 'A';
                else            t += (char)('A' + (s[i]-'A'+cnt+26*100)%26);
            }else{
                t += (s[i] != '?' ? s[i] : 'A');
            }
            i++;
        }
        stack<char> q;
        for(i = 0; i < t.length(); i++){
            if(t[i] == ']'){
                vector<char> r;
                while(q.top() != '[')   r.push_back(q.top()), q.pop();
                q.pop();
                for(char c : r)   q.push(c);
            }else{
                q.push(t[i]);
            }
        }
        string ans = "";
        while(!q.empty()){
            ans += q.top();    q.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}