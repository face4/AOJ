#include<iostream>
#include<cstring>
using namespace std;

bool b[7400000];

int main(){
    int m, n;
    while(cin >> m >> n, m+n){
        memset(b, 0, sizeof(b));
        int year = m;
        for(int i = 0; i < n; i++){
            while(b[year])  year++;
            for(int j = year; j < 7400000; j += year)   b[j] = true;
        }
        while(b[year])  year++;
        cout << year << endl;
    }
    return 0;
}