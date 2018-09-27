#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

string aiueo = "aiueo";

bool f(char x){
    return count(aiueo.begin(), aiueo.end(), x);
}

int main(){
    int n;
    while(cin >> n, n){
        vector<string> codes;
        string s;
        int ma = 0;

        for(int i = 0; i < n; i++){
            cin >> s;
            string code = "";
            code += s[0];
            for(int i = 0; i < s.length()-1; i++)   if(f(s[i])) code += s[i+1];
            codes.push_back(code);
            ma = max(ma, (int)code.length());
        }

        int k, i;
        for(k = 1; k <= ma; k++){
            set<string> se;
            for(i = 0; i < n; i++){
                string tmp;
                if(codes[i].length() >= k){
                    tmp = codes[i].substr(0,k);
                }else{
                    tmp = codes[i];
                }
                if(se.count(tmp))   break;
                se.insert(tmp);
            }
            if(i == n)  break;
        }

        cout << (k == ma+1 ? -1 : k) << endl;
    }
    return 0;
}