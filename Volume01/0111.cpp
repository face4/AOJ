#include<iostream>
#include<sstream>
#include<bitset>
#include<map>
using namespace std;

string bin(char x){
    stringstream ss;
    ss << bitset<5>(x-'A');
    string s = ss.str();
    return s;
}

int main(){
    map<char, string> enc;
    for(char c = 'A'; c <= 'Z'; c++){
        enc[c] = bin(c);
    }
    enc[' '] = "11010";
    enc['.'] = "11011";
    enc[','] = "11100";
    enc['-'] = "11101";
    enc['\''] = "11110";
    enc['?'] = "11111";

    map<string, char> dec;
    char c[32] = {' ', '\'', ',', '-', '.', '?', 'A', 'B',
                  'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string s[32] = {"101",
                    "000000",
                    "000011",
                    "10010001",
                    "010001",
                    "000001",
                    "100101",
                    "10011010",

                    "0101",
                    "0001",
                    "110",
                    "01001",
                    "10011011",
                    "010000",
                    "0111",
                    "10011000",

                    "0110",
                    "00100",
                    "10011001",
                    "10011110",
                    "00101",
                    "111",
                    "10011111",
                    "1000",

                    "00110",
                    "00111",
                    "10011100",
                    "10011101",
                    "000010",
                    "10010010",
                    "10010011",
                    "10010000"};
    for(int i = 0; i < 32; i++){
        dec[s[i]] = c[i];
    }

    string in;
    while(getline(cin, in)){
        string cry = "";
        for(char x : in){
            cry += enc[x];
        }
        int cur = 0;
        while(cur < cry.length()){
            int next = cur+1;
            while(next <= cry.length() && !dec.count(cry.substr(cur, next-cur))){
                next++;
            }
            if(next > cry.length()) break;
            cout << dec[cry.substr(cur, next-cur)];
            cur = next;
        }
        cout << endl;
    }
    return 0;
}