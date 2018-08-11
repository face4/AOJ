#include<iostream>
using namespace std;

int main(){
    while(1){
        int l;
        cin >> l;
        if(l == 0)  break;

        int m[12], n[12];
        for(int i = 0; i < 12; i++){
            cin >> m[i] >> n[i];
        }

        int sum = 0, month;
        for(month = 0; month < 12; month++){
            sum += m[month] - n[month];
            if(sum >= l)    break;
        }

        if(month == 12) cout << "NA" << endl;
        else            cout << month+1 << endl;
    }
    return 0;
}