#include<iostream>
#include<vector>
using namespace std;

void win(int id){
    cout << id+1 << endl;
    exit(0);
}

int main(){
    int n, t, h, l;
    cin >> n >> t >> h >> l;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];
    int turn = 0, acc = 0;
    while(true){
        if(a[turn]+b[turn] == 0)    win(turn);
        if(a[turn]){
            a[turn]--;
            acc += 1;
            t++;
            if(t > l)   win(turn);
        }else{
            b[turn]--;
            acc += 10;
            h++;
        }
        if(acc >= 9){
            t -= acc-9;
            if(t < 0)   win(turn);
            a[turn] += acc-9;
            acc = 0;
        }
        turn++;
        if(turn == n)   turn = 0;
    }
}