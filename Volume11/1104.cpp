#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
       int di = 1, dj = 0; 
       string op;
       int k, i = 0, j = 0;

       while(cin >> op, op != "STOP"){
           if(op.length() < 6){
               if(op == "LEFT"){
                   swap(di, dj);
                   dj = -dj;
               }else if(op == "RIGHT"){
                   swap(di, dj);
                   di = -di;
               }
           }else{
               cin >> k;
               int bias = (op == "FORWARD") ? 1 : -1;

               for(int x = 0; x < k; x++){
                   i += bias*di, j += bias*dj;
                   if(!inRange(i,0,h) || !inRange(j,0,w))   i -= bias*di, j -= bias*dj;
               }
           }
       }

       cout << j+1 << " " << i+1 << endl;
    }
    return 0;
}