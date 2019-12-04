#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int> id;
    map<int,string> di;
    id["ld"] = 26;  di[26] = "ld";
    id["mb"] = 27;  di[27] = "mb";
    id["mp"] = 28;  di[28] = "mp";
    id["nc"] = 29;  di[29] = "nc";
    id["nd"] = 30;  di[30] = "nd";
    id["ng"] = 31;  di[31] = "ng";
    id["nt"] = 32;  di[32] = "nt";
    id["nw"] = 33;  di[33] = "nw";
    id["ps"] = 34;  di[34] = "ps";
    id["qu"] = 35;  di[35] = "qu";
    id["cw"] = 36;  di[36] = "cw";
    id["ts"] = 37;  di[37] = "ts";
    
    int cnt[38][38] = {};

    int n;
    cin >> n;
    string s;
    while(cin >> s){
        int pos = 0, bef = -1;
        while(pos < s.length()){
            int aft;
            if(pos+1 < s.length() && id.count(s.substr(pos,2)) > 0){
                aft = id[s.substr(pos,2)];
                pos += 2;
            }else{
                aft = s[pos]-'a';
                pos++;
            }
            if(bef != -1)   cnt[bef][aft]++;
            bef = aft;
        }
    }
    for(int i = 0; i < 38; i++){
        int j = 0;
        for(int k = 1; k < 38; k++){
            if(cnt[i][j] < cnt[i][k])   j = k;
        }
        if(i < 26)  cout << (char)('a'+i);
        else        cout << di[i];
        cout << " ";
        if(j < 26)  cout << (char)('a'+j);
        else        cout << di[j];
        cout << " " << cnt[i][j] << endl;
    }
    return 0;
}