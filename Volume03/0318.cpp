#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool table[3][101] = {};

    for(int i = 0; i < 3; i++){
        int num;
        cin >> num;
        for(int j = 0; j < num; j++){
            int a;
            cin >> a;
            table[i][a] = true;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(table[2][i] && (!table[0][i] || table[1][i]))    cnt++;
    }

    cout << cnt << endl;
    return 0;
}