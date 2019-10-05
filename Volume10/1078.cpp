#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int enc(char c){
    if(inRange(c, 'a', 'z'))    return c-'a'+1;
    return c-'A'+26+1;
}

int main(){
    string s;
    while(cin >> s, s != "#"){
        int pos = 0;
        bool valid = false;
        while(pos < s.length()){
            vector<int> v;
            pos++;  // (
            for(int i = 0; i < 3; i++){
                int num = s[pos] == '~' ? 1 : -1;
                if(s[pos] == '~')   pos++;
                num *= s[pos++];
                v.push_back(num);
                pos++; // & or )
            }
            bool good = true;
            for(int i = 0; i < 3; i++){
                for(int j = i+1; j < 3; j++){
                    good &= v[i]+v[j]!=0;
                }
            }
            if(good)    valid = true;
            pos++;  // |
        }
        cout << (valid ? "yes" : "no") << endl;
    }
    return 0;
}