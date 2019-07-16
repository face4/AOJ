#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int ans[100];
    queue<int> row;
    int t = 0, cur = -1;
    vector<int> in(17, -1);
    while(cur != 99){
        // new customer
        if(t%5 == 0 && t < 500) row.push(t/5);

        // customer leaves
        for(int i = 0; i < 17; i++) if(t >= in[i]) in[i] = -1;

        // customer comes in
        while(!row.empty()){
            int next = row.front();
            int num = next%5==1 ? 5 : 2;
            int i;
            for(i = 0; i <= 17-num; i++){
                int vacant = 0;
                for(int j = 0; j < num; j++){
                    vacant += (in[i+j]==-1);
                }
                if(vacant == num){
                    break;
                }
            }
            if(i > 17-num)  break;
            // decide the position i
            row.pop();
            int tot = t + 17*(next%2)+3*(next%3)+19;
            for(int j = 0; j < num; j++){
                in[i+j] = tot;
            }
            ans[next] = t-next*5;
            cur = next;
        }

        // time passes
        t++;
    }

    int n;
    while(cin >> n)  cout << ans[n] << endl;
    return 0;
}