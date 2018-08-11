#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int c[10] = {};
        int a;
        while(n-- > 0){
            cin >> a;
            c[a]++;
        }
        for(int x : c){
            if(x){
                while(x-- > 0)  printf("*");
                printf("\n");
            }else{
                printf("-\n");
            }
        }
    }
    return 0;
}
