#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int x, y, b, p;
    while(n-- > 0){
        cin >> x >> y >> b >> p;
        cout << min(x*b + y*p, (int)(0.8*(max(5,b)*x + max(2,p)*y))) << endl;
    }
    return 0;
}
