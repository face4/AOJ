#include<iostream>
using namespace std;

int main(){
    int p;
    while(cin >> p){
        p %= 39;

        if(p == 0)  p = 39;

        printf("3C%02d\n", p);
    }

    return 0;
}