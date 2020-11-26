#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

const int INF = INT_MAX;

int main(){
    int n, q;
    cin >> n >> q;
    int bucket = sqrt(n)+1;
    int block[bucket], a[n];
    for(int i = 0; i < n; i++)  a[i] = INF;
    for(int i = 0; i < bucket; i++) block[i] = INF;
    auto getBucket = [=](int x)->int{
        return x/bucket;
    };
    while(q--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 0){
            a[x] = y;
            int ind = getBucket(x);
            block[ind] = INF;
            for(int j = 0; j < bucket; j++){
                if(ind*bucket+j < n)    block[ind] = min(block[ind], a[ind*bucket+j]);
            }
        }else if(op == 1){
            y++;
            int ret = INF;
            while(x < y && x%bucket){
                ret = min(ret, a[x++]);
            }
            while(x+bucket<y){
                ret = min(ret, block[getBucket(x)]);
                x += bucket;
            }
            while(x < y){
                ret = min(ret, a[x++]);
            }
            cout << ret << endl;
        }
    }
    return 0;
}