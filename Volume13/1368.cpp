#include<iostream>
using namespace std;

int op[10][10];

int f(string s){
    int ret = 0;
    for(int i = 0; i < s.length(); i++){
        ret = op[ret][s[i]-'0'];
    }
    return ret;
}

int main(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> op[i][j];
        }
    }

    int ans = 0;
    for(int x = 0; x < 10000; x++){
        string base = to_string(x);
        while(base.length() != 4)   base = "0" + base;
        base += (char)(f(base) + '0');

        bool correct = true;

        // altering one single digit
        for(int i = 0; i < 5; i++){
            base[i] = (char)((base[i]-'0'+1)%10 + '0');
            for(int j = 1; j < 10; j++){
                if(f(base) == 0)    correct = false;
                base[i] = (char)((base[i]-'0'+1)%10 + '0');
            }
        }
        
        // transposing two adjacent digits
        for(int i = 0; i < 4; i++){
            if(base[i] == base[i+1])    continue;
            swap(base[i], base[i+1]);
            if(f(base) == 0)    correct = false;
            swap(base[i], base[i+1]);
        }

        if(!correct)  ans++;
    }

    cout << ans << endl;

    return 0;
}