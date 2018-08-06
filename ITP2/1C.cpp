#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    int q, op, val;
    scanf("%d", &q);
    list<int>::iterator it = l.begin();

    for(int i = 0; i < q; i++){
        scanf("%d", &op);
        if(op == 0){
            scanf("%d", &val);
            it = l.insert(it, val);
        }else if(op == 1){
            scanf("%d", &val);
            if(val > 0){
                for(int i = 0; i < val; i++)   it++;
            }else{
                for(int i = 0; i < -val; i++)   it--;
            }
        }else if(op == 2){
            it = l.erase(it);
        }
    }
    
    for(it = l.begin(); it != l.end(); it++){
        printf("%d\n", *it);
    }

    return 0;
}