// これはなに?
#include<iostream>
#include<random>
using namespace std;

int main(){
    int n;
    cin >> n;
    char s[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    int e = rand()%n+1;
    for(int i = 0; i < 1000; i++){
        cout << e << endl;
        int x;  cin >> x;
        if(s[e-1][x-1] == 'x')  e = rand()%n+1;
    }
    return 0;
}