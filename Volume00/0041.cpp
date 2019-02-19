#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string op = "+-*";

int calc(int a, int b, char c){
    if(c == '+')    return a+b;
    if(c == '-')    return a-b;
    return a*b;
}

string s(int x){
    return to_string(x);
}

string s(char x){
    string tmp({x});
    return tmp;
}

int main(){
    vector<int> v(4);
    string ans;
    while(1){
        for(int i = 0; i < 4; i++)  cin >> v[i];
        sort(v.begin(), v.end());
        if(v[0] == 0)   break;
        bool found = false;
        do{
            for(int i = 0; i < 27; i++){
                char a = op[i/9], b = op[(i%9)/3], c = op[i%3];
                if(calc(calc(v[0], calc(v[1],v[2],b), a), v[3], c) == 10){
                    found = true; ans="("+s(v[0])+s(a)+"("+s(v[1])+s(b)+s(v[2])+"))"+s(c)+s(v[3]);
                }
                if(calc(v[0], calc(calc(v[1],v[2],b), v[3], c), a) == 10){
                    found = true; ans=s(v[0])+s(a)+"(("+s(v[1])+s(b)+s(v[2])+")"+s(c)+s(v[3])+")";
                }
                if(calc(calc(calc(v[0],v[1],a), v[2], b), v[3], c) == 10){
                    found = true; ans="(("+s(v[0])+s(a)+s(v[1])+")"+s(b)+s(v[2])+")"+s(c)+s(v[3]);
                }
                if(calc( calc(v[0],v[1],a), calc(v[2],v[3],c), b) == 10){
                    found = true; ans="("+s(v[0])+s(a)+s(v[1])+")"+s(b)+"("+s(v[2])+s(c)+s(v[3])+")";
                }
                if(calc(v[0], calc(v[1], calc(v[2],v[3],c), b), a) == 10){
                    found = true; ans=s(v[0])+s(a)+"("+s(v[1])+s(b)+"("+s(v[2])+s(c)+s(v[3])+"))";
                }
            }
            if(found)   break;
        }while(next_permutation(v.begin(), v.end()));
        if(!found)  cout << 0 << endl;
        else        cout << ans << endl;
    }
    return 0;
}
