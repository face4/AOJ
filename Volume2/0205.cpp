#include<iostream>
#include<set>
using namespace std;

int main(){
    while(1){
        int A[5];

        cin >> A[0];
        if(A[0] == 0)   break;

        set<int> appear;
        appear.insert(A[0]);
        for(int i = 1; i < 5; i++){
            cin >> A[i];
            appear.insert(A[i]);
        }

        if(appear.size() != 2){
            for(int i = 0; i < 5; i++)  cout << 3 << endl;
        }else{
            int win, lose;
            bool b[4] = {};
            for(int x : appear) b[x] = true;
            if(b[1] && b[2]){
                win = 1;
                lose = 2;
            }else if(b[2] && b[3]){
                win = 2;
                lose = 3;
            }else if(b[3] && b[1]){
                win = 3;
                lose = 1;
            }

            for(int i = 0; i < 5; i++){
                if(A[i] == win)         cout << 1 << endl;
                else if(A[i] == lose)   cout << 2 << endl;
            }
        }
    }
    return 0;
}
