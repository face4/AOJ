#include<iostream>
using namespace std;

int main(){
    int q1, b, c1, c2, q2;
    while(1){
        cin >> q1;
        if(q1 == 0) break;
        cin >> b >> c1 >> c2 >> q2;

        int aizu = min(q2, b/c1);
        b -= aizu * c1;
        int normal = b/c2;
        b -= normal * c2;

        if(aizu + normal < q1 && c1 > c2){
            while(aizu + normal < q1 && aizu > 0){
                aizu--;
                b += c1;
                normal += b/c2;
                b %= c2;
            }
        }

        if(aizu > 0 && aizu + normal >= q1) cout << aizu << " " << normal << endl;
        else                    cout << "NA" << endl;
    }
    return 0;
}