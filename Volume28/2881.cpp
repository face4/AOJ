#include<iostream>
using namespace std;

int main(){
    string g;
    int y, m, d;
    while(cin >> g, g != "#"){
        cin >> y >> m >> d;
        if(y>31 || (y==31 && m>=5))   g = "?", y -= 30;
        cout << g << " " << y << " " << m << " " << d << endl;
    }
    return 0;
}