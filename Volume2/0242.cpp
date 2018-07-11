#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

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

struct dict{
    string word;
    int freq;
    dict(string w, int f) : word(w), freq(f) {}
    bool operator<(const dict other) const{
        if(freq == other.freq)  return word < other.word;
        else                    return freq > other.freq;
    }
};

int main(){
    while(1){
        int n;
        scanf("%d\n", &n);
        
        if(n == 0)  break;
        
        map<string, int> appear;
        string s;
        for(int i = 0; i < n; i++){
            getline(cin, s);
            vector<string> line = split(s, ' ');
            for(string x : line)    appear[x]++;
        }
        
        char k;
        cin >> k;
        
        vector<dict> vd;
        for(map<string,int>::iterator it = appear.begin(); it != appear.end(); it++){
            pair<string,int> psi = *it;
            if(psi.first[0] == k)   vd.push_back(dict(psi.first, psi.second));
        }
        
        if(vd.size() == 0){
            cout << "NA" << endl;
            continue;
        }else{
            sort(vd.begin(), vd.end());
            for(int i = 0; i < min(5, (int)(vd.size())); i++){
                if(i)   cout << " ";
                cout << vd[i].word;
            }
            cout << endl;
        }
    }
    
    return 0;
}
