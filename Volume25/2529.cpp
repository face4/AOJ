#include<iostream>
#include<vector>
using namespace std;

int main(){
    for(int i = 0; i < 10; i++) cout << "+";
    cout << "[";
    for(int i = 3; i <= 12; i++){
        cout << ">";
        for(int j = 0; j < i; j++)  cout << "+";
    }
    for(int i = 3; i <= 12; i++)    cout << "<";
    cout << "-]>";

    vector<int> v(15, 0);
    for(int i = 3; i <= 12; i++){
        v[i] = i*10;
    }
    int pos = 3;
    
    string s;
    cin >> s;
    for(char c : s){
        int x = (int)c;
        while(pos+1 <= x/10)    cout << ">", pos++;
        while(pos-1 >= x/10)    cout << "<", pos--;
        while(v[pos]+1 <= x)    cout << "+", v[pos]++;
        while(v[pos]-1 >= x)    cout << "-", v[pos]--;
        cout << ".";
    }
    return 0;
}