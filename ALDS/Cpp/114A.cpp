#include<iostream>
using namespace std;

int main(){
    string t, p;
    cin >> t >> p;

    if(t.length() < p.length()) return 0;
    
    for(int i = 0; i <= t.length()-p.length(); i++){
        int j;
        for(j = 0; j < p.length(); j++){
            if(t[i+j] != p[j])  break;
        }
        if(j == p.length()) cout << i << endl;
    }


    return 0;
}