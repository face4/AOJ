#include<iostream>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int keta = s.length()-1, sum = 0;
        for(char c : s) sum += c-'0';
        cout << ((keta+(sum-1)/9)%2==0 ? "Audrey" : "Fabre") << " wins." << endl;
    }
    return 0;
}