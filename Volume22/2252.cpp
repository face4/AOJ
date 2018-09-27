#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string l = "qwertasdfgzxcvb";
    string s;
    while(cin >> s && s != "#"){
        bool left = count(l.begin(), l.end(), s[0]);
        int cnt = 0;
        for(int i = 1; i < s.length(); i++){
            if(count(l.begin(), l.end(), s[i]) != left){
                cnt++;
                left = !left;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}