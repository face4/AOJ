#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        string c[n+2];
        c[0] = c[n+1] = "x";
        for(int i = 1; i <= n; i++)  cin >> c[i];

        bool con = false;
        for(int i = 1; i < n; i++){
            if(c[i] == "x" && c[i+1] == "x")    con = true;
        }

        if(con){
            cout << "none" << endl;
            continue;
        }

        int lower = -1e9-10, upper = 1e9+10;
        bool valid = true;
        for(int i = 1; i <= n; i++){
            if(c[i] == "x"){
                if(i%2){
                    if(c[i-1] != "x")   upper = min(upper, stoi(c[i-1])-1);
                    if(c[i+1] != "x")   upper = min(upper, stoi(c[i+1])-1);
                }else{
                    if(c[i-1] != "x")   lower = max(lower, stoi(c[i-1])+1);
                    if(c[i+1] != "x")   lower = max(lower, stoi(c[i+1])+1);
                }
            }else{
                if(i%2){
                    if(c[i-1] != "x" && stoi(c[i]) >= stoi(c[i-1]))   valid = false;
                    if(c[i+1] != "x" && stoi(c[i]) >= stoi(c[i+1]))   valid = false;
                }else{
                    if(c[i-1] != "x" && stoi(c[i]) <= stoi(c[i-1]))   valid = false;
                    if(c[i+1] != "x" && stoi(c[i]) <= stoi(c[i+1]))   valid = false;
                }
            }
        }

        valid &= lower <= upper;

        if(valid){
            if(lower == upper)  cout << lower << endl;
            else                cout << "ambiguous" << endl;
        }else{
            cout << "none" << endl;
        }

    }
    return 0;
}