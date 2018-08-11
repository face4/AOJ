#include<iostream>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;

        if(n == 0)  break;

        int A[n];
        for(int i = 0; i < n; i++)  cin >> A[i];

        int cnt = 0;
        for(int i = n-1; i > 0; i--){
            for(int j = 0; j < i; j++){
                if(A[j] > A[j+1]){
                    swap(A[j], A[j+1]);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}