#include<iostream>
using namespace std;

int main(){
    int e, y;
    cin >> e >> y;

    if(e == 0){
        if(y >= 1989)       cout << "H" << y-1989+1 << endl;
        else if(y >= 1926)  cout << "S" << y-1926+1 << endl;
        else if(y >= 1912)  cout << "T" << y-1912+1 << endl;
        else if(y >= 1868)  cout << "M" << y-1868+1 << endl;
    }else if(e == 1){
        cout << 1868+y-1 << endl;
    }else if(e == 2){
        cout << 1912+y-1 << endl;
    }else if(e == 3){
        cout << 1926+y-1 << endl;
    }else if(e == 4){
        cout << 1989+y-1 << endl;
    }

    return 0;
}