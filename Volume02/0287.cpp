#include<iostream>
using namespace std;

int main(){
    string suf[18] = {"", "Man", "Oku", "Cho", "Kei", "Gai", "Jo", "Jou", "Ko", 
                    "Kan", "Sei", "Sai", "Gok", "Ggs", "Asg", "Nyt", "Fks", "Mts"};

    int m, n;
    while(cin >> m >> n, m+n){
        int d[18] = {};
        d[0] = 1;

        for(int i = 0; i < n; i++){
            int carry = 0;
            for(int j = 0; j < 18; j++){
                d[j] = d[j]*m + carry;
                carry = d[j]/10000;
                d[j] %= 10000;
            }
        }

        for(int i = 17; i >= 0; i--){
            if(d[i])    cout << d[i] << suf[i];
        }
        cout << endl;
    }
    
    return 0;
}