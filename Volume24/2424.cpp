#include<iostream>
using namespace std;

int modify(int n){
    string s = to_string(n);
    int ret = -1;
    for(int i = 1; i < s.length(); i++){
        string a = s.substr(0,i), b = s.substr(i);
        ret = max(ret, stoi(a)*stoi(b));
    }
    return ret;
}

int main(){
    int q;
    cin >> q;

    int n;
    while(q-- > 0){
        cin >> n;
        int step = 0;
        while(n > 9){
            n = modify(n);
            step++;
        }
        cout << step << endl;
    }

    return 0;
}