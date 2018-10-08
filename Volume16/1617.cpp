#include<iostream>
#include<vector>
using namespace std;

string exec(vector<string> &v, string s){
    string ret = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '"'){
            i++;
            string tmp = "";
            while(i < s.length() && s[i] != '"')  tmp += s[i], i++;
            v.push_back(tmp);
            ret += "_";
        }else{
            ret += s[i];
        }
    }
    return ret;
}

int main(){
    string s, t;
    while(cin >> s, s != "."){
        cin >> t;
        int slen = s.length(), tlen = t.length();
        vector<string> vs, vt;
        string ss = exec(vs, s);
        string tt = exec(vt, t);
        
        if(ss != tt || vs.size() != vt.size()){
            cout << "DIFFERENT" << endl;
            continue;
        }

        int cnt = 0;
        for(int i = 0; i < vs.size(); i++){
            if(vs[i] != vt[i])  cnt++;
        }

        if(cnt == 0){
            cout << "IDENTICAL" << endl;
        }else if(cnt == 1){
            cout << "CLOSE" << endl;
        }else if(cnt > 1){
            cout << "DIFFERENT" << endl;
        }

    }

    return 0;
}