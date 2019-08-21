#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

string s;

int f(int &pos){
    if(s[pos] == '['){
        vector<int> child;
        pos++;
        while(true){
            child.push_back(f(pos));
            if(s[pos] == ']'){
                pos++;
                break;
            }
        }
        sort(child.begin(), child.end());
        int ret = 0;
        for(int i = 0; i <= child.size()/2; i++)    ret += child[i];
        return ret;
    }else{
        int ret = 0;
        while(isdigit(s[pos]))  ret = ret*10 + (s[pos++]-'0');
        return ret/2+1;
    }
}

int main(){
    int n, pos;
    cin >> n;
    while(n-- > 0){
        cin >> s;
        pos = 0;
        cout << f(pos) << endl;
    }
    return 0;
}