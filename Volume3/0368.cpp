#include<iostream>
using namespace std;

int main(){
    int w, h;
    char c;
    cin >> w >> h >> c;
    
    printf("+");
    for(int i = 0; i < w-2; i++)    printf("-");
    printf("+\n");

    for(int i = 0; i < h-2; i++){
        for(int j = 0; j < w; j++){
            if(j == 0 || j == w-1)                  printf("|");
            else if(i == (h-2)/2 && j == w/2)   printf("%c", c);
            else                                    printf(".");
        }
        printf("\n");
    }

    printf("+");
    for(int i = 0; i < w-2; i++)    printf("-");
    printf("+\n");

    return 0;
}
