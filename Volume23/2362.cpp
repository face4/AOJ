#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> v;
    int i = 0;
    while(i < s.length()){
        if(s[i] == 'e'){
            v.push_back(0);
            i += 3;
        }else if(s[i] == 'c'){
            v.push_back(1);
            i += 7;
        }
    }
    int dep = 0, tmp = 0, ans = -1, bef = -1;
    for(int i = 0; i < v.size(); i++){
        if(bef == v[i]){
            tmp = 1;
        }else{
            tmp++;
        }
        if(tmp > dep){
            dep = tmp;
            ans = v[i];
        }
        bef = v[i];
    }
    cout << (ans==0 ? "egg" : "chicken") << endl;
    return 0;
}
