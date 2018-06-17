// 愚直解
// もっとスッキリ書きたい
#include<iostream>
using namespace std;

int main(){
    int way[15] = {0,1,2,3,4,5,6,7,8,9,5,4,3,2,1};

    int n, from, to, ansf, anst;
    cin >> n;

    for(int i = 0; i < n; i++){
        int length = 20;
        cin >> from >> to;
        for(int start = 0; start < 15; start++){
            if(way[start] == from){
                int tmp = 1;
                int now = start;
                while(way[now] != to){
                    tmp++;
                    now = (now+1)%15;
                }

                if(length > tmp){
                    ansf = start;
                    anst = now;
                    length = tmp;
                }

            }
        }

        for(int i = 0; i < length; i++){
            if(i)   cout << " ";
            cout << way[(ansf+i)%15];
        }
        cout << endl;

    }

    return 0;
}