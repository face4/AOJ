#include<iostream>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;

vector<string> split(string s){
    vector<string> ret;
    
    string tmp = s.substr(0,1);
    tmp[0] = tolower(tmp[0]);

    for(int i = 1; i < s.length(); i++){
        if(s[i] == '_'){
            ret.push_back(tmp);
            tmp = "";
        }else if(isupper(s[i])){
            ret.push_back(tmp);
            tmp = s.substr(i, 1);
            tmp[0] = tolower(tmp[0]);
        }else{
            tmp += s.substr(i,1);
        }
    }

    if(tmp != "")   ret.push_back(tmp);
    
    return ret;
}

int main(){
    string s;
    char op;
    while(cin >> s >> op){
        if(op == 'X')   break;

        vector<string> v = split(s);
        int n = v.size();

        if(op == 'L'){
            cout << v[0];
            for(int i = 1; i < n; i++){
                v[i][0] = toupper(v[i][0]);
                cout << v[i];
            }
            cout << endl;
        }else if(op == 'U'){
            for(int i = 0; i < n; i++){
                v[i][0] = toupper(v[i][0]);
                cout << v[i];
            }
            cout << endl;
        }else if(op == 'D'){
            for(int i = 0; i < n; i++){
                cout << v[i] << "_\n"[i == n-1];
            }
        }
    }
    return 0;
}