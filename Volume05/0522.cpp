#include<iostream>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int joi = 0, ioi = 0;
        for(int i = 0; i <= s.length()-3; i++){
            if(s[i]=='J'&&s[i+1]=='O'&&s[i+2]=='I') joi++;
            if(s[i]=='I'&&s[i+1]=='O'&&s[i+2]=='I') ioi++;
        }
        cout << joi << endl << ioi << endl;
    }
    return 0;
}
