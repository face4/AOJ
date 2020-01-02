#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ret = 0;
    while(n--){
        string s;
        cin >> s;
        ret += s == "E869120";
    }
    cout << ret << endl;
    return 0;
}
