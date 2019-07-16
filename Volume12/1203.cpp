#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define inRange(x, a, b) (a <= x && x <= b)

int main(){
    string l;
    while(getline(cin, l)){
        string s = "";
        for(char c : l){
            if(inRange(c, 'a', 'z'))    s += (char)(c-'a'+'A');
            if(inRange(c, 'A', 'Z'))    s += c;
        }
        int n = s.length();
        set<string> res;
        for(int i = 1; i+1 < n; i++){
            int x = i, y = i;
            while(x-1 >= 0 && y+1 < n && s[x-1]==s[y+1])    x--, y++;
            if(y != x)  res.insert(s.substr(x, y-x+1));
            if(s[i] != s[i+1])  continue;
            x = i, y = i+1;
            while(x-1 >= 0 && y+1 < n && s[x-1]==s[y+1])    x--, y++;
            if(y-x != 1)    res.insert(s.substr(x, y-x+1));
        }
        vector<string> odd, even;
        for(auto it = res.begin(); it != res.end(); it++){
            string tmp = *it;
            if(tmp.size()%2)    odd.push_back(tmp);
            else                even.push_back(tmp);
        }
        auto cp = [](string s, string t)->bool{
            return s.length() < t.length();
        };
        sort(odd.begin(), odd.end(), cp);
        sort(even.begin(), even.end(), cp);
        // cover?
        for(int i = 0; i < odd.size(); i++){
            for(int j = i+1; j < odd.size(); j++){
                int center = odd[j].size()/2;
                int ilen = odd[i].size();
                if(odd[j].substr(center-ilen/2, ilen) == odd[i]){
                    res.erase(odd[i]);
                    break;
                }
            }
        }
        // for(int i = 0; i < even.size(); i++){
        //     for(int j = i+1; j < even.size(); j++){
        //         int center = even[j].size()/2;
        //         int ilen = even[i].size();
        //         if(even[j].substr(center-ilen/2, ilen) == even[i]){
        //             res.erase(even[i]);
        //             break;
        //         }
        //     }
        // }
        if(res.begin() != res.end()){
            cout << *res.begin();
        }else{
            cout << endl;
            continue;
        }
        for(set<string>::iterator it = ++res.begin(); it != res.end(); it++)    cout << " " << *it;
        cout << endl;
    }
    return 0;
}