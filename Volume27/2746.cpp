#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    while(cin >> s, s != "#"){
        vector<string> v;
        int pos = 0;
        string acc = "";
        while(pos < s.length()){
            if(s[pos] == '/'){
                v.push_back(acc);
                acc = "";
            }else if(s[pos] == 'b'){
                acc += "b";
            }else{
                for(int i = 0; i < s[pos]-'0'; i++) acc += ".";
            }
            pos++;
        }
        v.push_back(acc);
        int h = v.size(), w = v[0].size();
        int di, dj;
        cin >> di >> dj;
        v[di-1][dj-1] = '.';
        cin >> di >> dj;
        v[di-1][dj-1] = 'b';
        for(int i = 0; i < h; i++){
            int j = 0;
            while(j < w){
                if(v[i][j]=='b'){
                    cout << 'b';
                    j++;
                }else{
                    int nj = j;
                    while(nj < w && v[i][nj]=='.')  nj++;
                    cout << nj-j;
                    j = nj;
                }
            }
            cout << "/\n"[i+1==h];
        }
    }
    return 0;
}