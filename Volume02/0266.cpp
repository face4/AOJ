#include<iostream>
using namespace std;

int main(){
    int way[6][2] = {
        {3, 4} ,
        {4, 3} ,
        {1, 4} ,
        {-1, 5} ,
        {3, -1} ,
        {2, 1}
    };

    string p;
    int now;

    while(cin >> p){
        if(p == "#")    break;

        int now = 0;
        for(int i = 0; now != -1 && i < p.length(); i++){
            if(p[i] == '0'){
                now = way[now][0];
            }else if(p[i] == '1'){
                now = way[now][1];
            }
        }

        if(now != 1){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
        
    }

    return 0;
}