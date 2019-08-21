#include<iostream>
#include<algorithm>
using namespace std;

bool p(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;;i++){
        for(int j : {-1, 1}){
            if(p(to_string(n+i*j))){
                cout << n+i*j << endl;
                return 0;
            }
        }
    }
}