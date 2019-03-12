#include<iostream>
#include<cctype>
using namespace std;

int main(){
    int al[26] = {}, num[10] = {};
    string s;   cin >> s;
    for(char c : s){
        if(isdigit(c))  num[c-'0']++;
        else            al[c-'a']++;
    }
    int comp = 0;
    int cur = 0;
    while(cur < 26){
        if(al[cur] == 0){
            cur++;
            continue;
        }
        int next = cur;
        while(al[next] && next < 26){
            next++;
        }
        if(next-cur > 3){
            comp+= 3;
            while(cur < next){
                al[cur++]--;
            }
            cur = 0;
        }else{
            cur = next;
        }
    }
    cur = 0;
    while(cur < 10){
        if(num[cur] == 0){
            cur++;
            continue;
        }
        int next = cur;
        while(num[next] && next < 10){
            next++;
        }
        if(next-cur > 3){
            comp+= 3;
            while(cur < next){
                num[cur++]--;
            }
            cur = 0;
        }else{
            cur = next;
        }
    }
    for(int i = 0; i < 26; i++) comp += al[i];
    for(int i = 0; i < 10; i++) comp += num[i];
    cout << comp << endl;
    return 0;
}