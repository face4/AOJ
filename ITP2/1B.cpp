#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    int q, a, b, c;
    cin >> q;

    for(int i = 0; i < q; i++){
        scanf("%d", &a);
        if(a == 0){
            scanf("%d", &b);
            scanf("%d", &c);
            if(b == 0)  dq.push_front(c);
            else if(b == 1) dq.push_back(c);
        }else if(a == 1){
            scanf("%d", &b);
            printf("%d\n", dq[b]);
        }else if(a == 2){
            scanf("%d", &b);
            if(b == 0)  dq.pop_front();
            else if(b == 1) dq.pop_back();
        }
    }

    return 0;
}