#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int topping[n];
    for(int i = 0; i < n; i++)  cin >> topping[i];

    sort(topping, topping+n);
    reverse(topping, topping+n);

    int cal = c, cost = a;
    for(int i = 0; i < n; i++){
        int ncal = cal + topping[i];
        int ncost = cost + b;
        if((double)ncal/ncost >= (double)cal/cost){
            cal = ncal, cost = ncost;
        }else{
            break;
        }
    }

    cout << cal/cost << endl;

    return 0;
}