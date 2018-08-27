#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int appear[7] = {}, domino[7] = {};
        bool hasDup[7] = {};
        int a;

        for(int i = 0; i < n; i++){
            cin >> a;
            appear[a/10]++;
            appear[a%10]++;
            domino[a/10]++;
            if(a/10 != a%10)    domino[a%10]++;
            else                hasDup[a/10] = true;
        }

        int odd = 0;
        for(int i = 0; i < 7; i++){
            if(appear[i]%2) odd++;
        }

        bool judge = true;
        for(int i = 0; i < 7; i++){
            if(hasDup[i] && domino[i] == 1) judge = false;
        }

        bool rule1 = (odd == 0 || odd == 2);
        bool rule2 = (judge || n == 1);
        
        if(rule1 && rule2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}