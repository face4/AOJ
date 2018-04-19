#include<iostream>
#include<algorithm>

using namespace std;

struct P{
    char name[20];
    int t;
};

const int SIZE = 1000002;
P que[SIZE];
int head, tail, n;

void enqueue(P x){
    que[tail] = x;
    tail = (tail + 1) % SIZE;
}

P deque(){
    P tmp = que[head];
    head = (head + 1) % SIZE;
    return tmp;
}

int main(){
    int elaps = 0;
    int c,i,q;
    P u;

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> que[i].name >> que[i].t;
    }
    head = 1, tail = n+1;

    while(head != tail){
        u = deque();
        c = min(u.t, q); // 処理を行う
        u.t -= c;
        elaps += c;
        if(u.t > 0) enqueue(u);
        else    cout << u.name << " " << elaps << endl;
    }

    return 0;
}