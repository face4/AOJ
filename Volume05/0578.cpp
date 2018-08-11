#include<iostream>
using namespace std;

bool check(string b, string n){
    int blen = b.length();
    int nlen = n.length();
    for(int i = 0; nlen+(nlen-1)*i <= blen; i++){
        for(int j = 0; j <= blen-(nlen+(nlen-1)*i); j++){
            int k;
            for(k = 0; k < nlen; k++){
                if(n[k] != b[j + k*(i+1)])  break;
            }
        
            if(k == nlen) return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    
    string name, board;
    cin >> name;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> board;
        if(check(board, name))  cnt++;
    }

    cout << cnt << endl;
    return 0;
}