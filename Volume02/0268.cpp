#include<iostream>
#include<algorithm>
#include<iostream>
using namespace std;

int hextodec(char c){
    if(c <= '9')    return c-'0';
    return 10 + c-'a';
}

string dec(char x){
    int num = hextodec(x);
    string res = "";
    for(int i = 0; i < 4; i++){
        if(num & (1<<i))    res += "1";
        else                res += "0";
    }
    reverse(res.begin(), res.end());
    return res;
}


int main(){
    int bias[32] = {};
    for(int i = 1; i < 25; i++){
        bias[i] = 1<<(24-i);
    }
    bias[25] = 5000000;
    for(int i = 26; i < 32; i++){
        bias[i] = bias[i-1]/2;
    }

    int q;
    cin >> q;
    
    string s;

    while(q-- > 0){
        cin >> s;
        string bin = "";
        for(char c : s) bin += dec(c);
        int a = 0, b = 0;
        for(int i = 1; i < 25; i++){
            if(bin[i] == '1')   a += bias[i];
        }
        for(int i = 25; i < 32; i++){
            if(bin[i] == '1')   b += bias[i];
        }

        string sb = to_string(b);
        while(sb.length() != 7) sb = "0" + sb;
        while(sb.length() > 0 && sb[sb.length()-1] == '0')  sb = sb.substr(0, sb.length()-1);
        if(sb == "")    sb = "0";
        
        if(bin[0] == '1')   cout << "-";
        cout << a << "." << sb << endl;
    }

    return 0;
}