#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, q, op, a, b;
    cin >> n >> q;
    vector<int> A[n];

    for(int i = 0; i < q; i++){
        scanf("%d", &op);
        if(op == 0){
            scanf("%d %d", &a, &b);
            A[a].push_back(b);
        }else if(op == 1){
            scanf("%d", &a);
            for(int i = 0; i < A[a].size(); i++){
                if(i)   printf(" ");
                printf("%d", A[a][i]);
            }
            printf("\n");
        }else if(op == 2){
            scanf("%d", &a);
            A[a].clear();
        }
    }

    return 0;
}