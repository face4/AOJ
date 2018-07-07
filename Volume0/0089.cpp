#include<iostream>
#include<vector>
using namespace std;

// strをdelで区切る.いずれdelがstringでも大丈夫なように作り変える.
vector<string> split(string str, char del){
    vector<string> ret;
    string cutoff = "";
    for(int i = 0; i < str.length(); i++){
        if(str[i] == del){
            if(cutoff != "")    ret.push_back(cutoff);
            cutoff = "";
        }else{
            cutoff += str[i];
        }
    }
    if(cutoff != "")    ret.push_back(cutoff);
    return ret;
}

int main(){
    string s;
    vector<int> v;
    v.push_back(0);
    v.push_back(0);

    while(getline(cin, s)){
        vector<int> u;
        u.push_back(0);
        vector<string> line = split(s, ',');
        if(v.size() - 2 > line.size()){
            // ひし形は減衰
            for(int i = 0; i < line.size(); i++){
                u.push_back(max(v[i+1], v[i+2]) + stoi(line[i]));
            }
        }else{
            // ひし形は成長
            for(int i = 0; i < line.size(); i++){
                u.push_back(max(v[i], v[i+1]) + stoi(line[i]));
            }
        }
        u.push_back(0);
        v = u;
    }

    cout << v[1] << endl;

    return 0;
}