#include<iostream>
using namespace std;

int main(){
    int w, x, y, z, a, b, c, d;
    cin >> w >> x >> y >> z >> a >> b >> c >> d;

    int hiroshi = w*a + x*b + w/10 * c + x/20 * d;
    int kenjiro = y*a + z*b + y/10 * c + z/20 * d;

    if(hiroshi > kenjiro)       cout << "hiroshi" << endl;
    else if(hiroshi < kenjiro)  cout << "kenjiro" << endl;
    else if(hiroshi == kenjiro) cout << "even" << endl;
    
    return 0;
}