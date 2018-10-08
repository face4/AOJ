#include<iostream>
using namespace std;

int main(){
    int n, q, x;
    while(cin >> n >> q, n+q){
        string name[n];
        int by[n], wy[n];
        for(int i = 0; i < n; i++)  cin >> name[i] >> by[i] >> wy[i];
        for(int i = 0; i < q; i++){
            cin >> x;
            int j;
            for(j = 0; j < n; j++){
                if(wy[j] >= x && x >= wy[j]-by[j]+1)    break;
            }

            if(j == n){
                cout << "Unknown" << endl;
            }else{
                cout << name[j] << " " << x - (wy[j]-by[j]) << endl;
            }
        }
    }
    return 0;
}