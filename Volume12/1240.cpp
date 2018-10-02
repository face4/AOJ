#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

void relay(char op, string &s){

}

int main(){
    int n;
    cin >> n;

    while(n-- > 0){
        string op, s;
        cin >> op >> s;

        reverse(op.begin(), op.end());
        int len = s.length();
        
        for(char x : op){
            if(x == 'J'){
                s = s.substr(len-1, 1) + s.substr(0, len-1);
            }else if(x == 'C'){
                s = s.substr(1) + s.substr(0,1);
            }else if(x == 'E'){
                if(len % 2 == 1){
                    s = s.substr(len/2+1) + s[len/2] + s.substr(0, len/2);
                }else{
                    s = s.substr(len/2) + s.substr(0, len/2);
                }
            }else if(x == 'A'){
                reverse(s.begin(), s.end());
            }else if(x == 'P'){
                for(int i = 0; i < len; i++){
                    if(isdigit(s[i]))   s[i] = '0' + (s[i]-'0'-1+10)%10;
                }
            }else if(x == 'M'){
                for(int i = 0; i < len; i++){
                    if(isdigit(s[i]))   s[i] = '0' + (s[i]-'0'+1)%10;
                }
            }
        }

        cout << s << endl;
    }
    return 0;
}