#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, int> update;
    int n, a, d, m, x, y, z, k;
    cin >> n >> a >> d >> m;
    while(m-- > 0){
        cin >> x >> y >> z;
        y--, z--;
        if(x == 0){
            int toy = (update.count(z) ? update[z] : z);
            int toz = (update.count(y) ? update[y] : y);
            update[y] = toy, update[z] = toz;
        }else{
            if(update.count(z)){
                update[y] = update[z];
            }else{
                update[y] = z;
            }
        }
    }
    cin >> k; k--;
    cout << (update.count(k) ? a + (update[k])*d : a + k*d) << endl;
    return 0;
}