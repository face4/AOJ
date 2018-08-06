#include<iostream>
using namespace std;

int main(){
    int n, cnt = 0, area;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> area;
        for(int x = 1; 2*x*x + 2*x <= area; x++){
            if((area-x)%(2*x+1) == 0){
                cnt++;
                break;
            }
        }
    }

    cout << n-cnt << endl;

    return 0;
}