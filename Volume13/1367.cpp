#include<iostream>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int e[m];
    for(int i = 0; i < m; i++)  scanf("%d", e+i);

    bool used[200001] = {};

    for(int i = m-1; i >= 0; i--){
        if(used[e[i]])  continue;

        used[e[i]] = true;
        printf("%d\n", e[i]);
    }

    for(int i = 1; i <= n; i++) if(!used[i])    printf("%d\n", i);
    
    return 0;
}