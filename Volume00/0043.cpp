#include<iostream>
#include<vector>
using namespace std;

bool ch(int two, vector<int> v){
    if(v[two] < 2)  return false;
    v[two] -= 2;
    for(int i = 0; i < 9; i++){
        if(v[i] >= 3)   v[i] -= 3;
        while(i <= 6 && v[i] && v[i+1] && v[i+2]) v[i]--, v[i+1]--, v[i+2]--;
        if(v[i])    return false;
    }
    return true;
}

bool check(vector<int> v){
    for(int i = 0; i < 9; i++){
        if(ch(i, v))    return true;
    }
    return false;
}

int main(){
    string s;
    while(cin >> s){
        vector<int> v(9, 0);
        for(char x : s) v[x-'1']++;
        
        vector<int> res;
        for(int i = 0; i < 9; i++){
            if(v[i] >= 4)   continue;
            v[i]++;
            if(check(v))    res.push_back(i+1);
            v[i]--;
        }
        if(res.size() == 0) res.push_back(0);
        
        for(int i = 0; i < res.size(); i++) cout << res[i] << " \n"[i == res.size()-1];
    }

    return 0;
}