#include<iostream>
#include<cctype>
using namespace std;

bool comp(string s, string t){
    if(s.length() == t.length())    return s < t;
    return s.length() < t.length();
}

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        char mat[h][w];
        for(int i = 0; i < w*h; i++)    cin >> mat[i/w][i%w];

        string s[h][w];
        for(int i = 0; i < h*w; i++)    s[i/w][i%w] = "";

        string ans = "";

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!isdigit(mat[i][j])) continue;
                
                string prefix = "";
                if(i != 0 && s[i-1][j] != "") prefix = s[i-1][j];
                if(j != 0 && comp(prefix, s[i][j-1]))  prefix = s[i][j-1];
                prefix += mat[i][j];
                
                if(prefix == "0")   continue;
                
                s[i][j] = prefix;
                if(comp(ans, prefix))   ans = prefix;
            }
        }

        cout << ans << endl;
    }
    return 0;
}