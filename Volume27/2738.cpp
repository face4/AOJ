#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    int a = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "A"){
            a++;
        }else if(s == "Un"){
            a--;
            if(a < 0){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    cout << (a == 0 ? "YES" : "NO") << endl;

    return 0;
}