#include<iostream>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    int score = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        score += max(0, x-d);
    }
    if(score == 0)  cout << "kusoge" << endl;
    else            cout << score << endl;
    return 0;
}
