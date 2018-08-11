#include<iostream>
using namespace std;

char encrypt(char x, int a, int b){
    return (char)(((x-'a') * a + b)%26 + 'a');
}

int main(){
    int n;
    scanf("%d\n", &n);

    string str, copy;
    for(int i = 0; i < n; i++){
        getline(cin, str);
        int a, b;
        bool found = false;
        for(a = 1; !found ; a++){
            if(a % 2 == 0 || a % 13 == 0)    continue;
            for(b = 1; b <= 26; b++){
                copy = str;
                for(int k = 0; k < str.length(); k++){
                    if(str[k] != ' ')   copy[k] = encrypt(str[k], a, b);
                }
                if(copy.find("this") != -1 || copy.find("that") != -1){
                    cout << copy << endl;
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}