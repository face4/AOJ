#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    while(cin>>a>>b>>c>>d>>e>>f, a+b+c+d+e+f){
        a += d, b += e, c += f;
        int x = 0;
        for(int t = 0; t < 3; t++){
            if(a < t || b < t || c < t)   break;
            x = max(x, t + (a-t)/3 + (b-t)/3 + (c-t)/3);
        }
        cout << x << endl;
    }
    return 0;
}