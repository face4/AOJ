#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ind = -1, ans = 1<<30;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(x < ans){
            ind = i;
            ans = x;
        }
    }
    cout << ind+1 << endl;
    return 0;
}
