#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i])    return false;
    }
    return true;
}

int main(){
    int n, l;
    cin >> n >> l;
    multiset<string> m;
    for(int i = 0; i < n; i++){
        string s;   cin >> s;
        m.insert(s);
    }
    multiset<string> twin, solo;
    while(!m.empty()){
        string s = *m.begin();  m.erase(m.begin());
        string t = s;
        reverse(t.begin(), t.end());
        if(m.count(t)){
            twin.insert(min(s, t));
            m.erase(m.find(t));
        }else if(isPalindrome(s)){
            solo.insert(s);
        }
    }
    stack<string> rev;
    for(auto it = twin.begin(); it != twin.end(); it++){
        rev.push(*it);
        cout << *it;
    }
    if(!solo.empty())   cout << *solo.begin();
    while(!rev.empty()){
        string s = rev.top();   rev.pop();
        reverse(s.begin(), s.end());
        cout << s;
    }
    cout << endl;
    return 0;
}