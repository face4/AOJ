#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a, b;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        int color = min(a, min(b, min(n-a+1, n-b+1))) % 3;
        if(color == 0)  color = 3;
        cout << color << endl;
    }   

    return 0;
}