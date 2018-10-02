#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int a[26] = {};
        char c[n];
        for(int i = 0; i < n; i++)  cin >> c[i];

        bool found = false;
        char ansc;
        int ansi;

        for(int i = 0; i < n; i++){
            a[c[i]-'A']++;
            int ma = max_element(a, a+26)-a;
            bool judge = true;
            for(int j = 0; j < 26; j++){
                if(j == ma) continue;
                if(a[j] + (n-1-i) >= a[ma]) judge = false;
            }

            if(judge){
                found = true;
                ansc = 'A' + ma;
                ansi = i+1;
                break;
            }
        }

        if(found){
            cout << ansc << " " << ansi << endl;
        }else{
            cout << "TIE" << endl;
        }

    }
    return 0;
}