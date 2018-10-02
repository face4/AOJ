#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    string s;
    while(cin >> s, s != "#"){
        int pos = s.length()-1;
        int child = 0, mother = 1<<20;

        for(int i = 0; pos >= 0; i++){
            if(s[pos] == 'h'){
                if(i)   child -= 90 * (1<<(20-i));
                pos -= 5;
            }else if(s[pos] == 't'){
                child += 90 * (1<<(20-i));
                pos -= 4;
            }
        }

        int g = gcd(child, mother);
        child /= g, mother /= g;

        if(mother == 1){
            cout << child << endl;
        }else{
            cout << child << "/" << mother << endl;
        }
    }
    return 0;
}