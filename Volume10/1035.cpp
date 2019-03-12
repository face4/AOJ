#include<iostream>
using namespace std;

int main(){
    int w, q;
    while(cin >> w >> q, w+q){
        int a[w];   for(int i = 0; i < w; i++)  a[i] = -1;
        while(q-- > 0){
            char op;
            int x, y;
            cin >> op;
            if(op == 's'){
                cin >> x >> y;
                bool sleep = false;
                for(int j = 0; j <= w-y; j++){
                    int k;
                    for(k = 0; k < y; k++)  if(a[j+k] != -1)    break;
                    if(k == y){
                        for(k = 0; k < y; k++)  a[j+k] = x;
                        sleep = true;
                        cout << j << endl;
                        break;
                    }
                }
                if(!sleep)  cout << "impossible" << endl;
            }else{
                cin >> x;
                for(int i = 0; i < w; i++)  if(a[i] == x)   a[i] = -1;
            }
        }
        cout << "END" << endl;
    }
    return 0;
}