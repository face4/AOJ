#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;

const double EPS = 0.00000001;

int main(){
    int n;
    while(cin >> n, n){
        int str[n];
        for(int i = 0; i < n; i++)  cin >> str[i];

        int x, y, z;
        double score = DBL_MAX;
        for(int s = 0; s <= 15; s++){
            for(int a = 0; a <= 15; a++){
                for(int c = 0; c <= 15; c++){
                    int r[n+1];
                    r[0] = s;
                    for(int i = 1; i < n+1; i++)  r[i] = (a*r[i-1]+c)%256;

                    int ap[256] = {};
                    for(int i = 0; i < n; i++)  ap[(str[i]+r[i+1])%256]++;

                    double tmp = 0;
                    for(int i = 0; i < 256; i++){
                        if(ap[i] == 0)  continue;
                        double ratio = (double)ap[i]/n;
                        tmp += -ratio * log(ratio);
                    }

                    if(tmp+EPS < score) score = tmp, x = s, y = a, z = c;
                }
            }
        }

        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}