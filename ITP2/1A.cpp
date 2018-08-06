#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int q, op, val;
    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        scanf("%d", &op);
        if(op == 0){
            scanf("%d", &val);
            v.push_back(val);
        }else if(op == 1){
            scanf("%d", &val);
            cout << v[val] << endl;
        }else if(op == 2){
            v.pop_back();
        }
    }

    return 0;
}