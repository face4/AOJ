#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

struct button{
    int a[4];
    string to;
};

int main(){
    int n;
    while(cin >> n, n){
        int w, h;
        cin >> w >> h;

        map<int, string> iton;
        map<string, int> ntoi;
        vector<button> v[n];
        for(int i = 0; i < n; i++){
            string name;
            int b;

            cin >> name >> b;

            ntoi[name] = i;
            iton[i] = name;

            while(b-- > 0){
                button x;
                for(int j = 0; j < 4; j++)  cin >> x.a[j];
                cin >> x.to;
                v[i].push_back(x);
            }
        }

        int m;
        cin >> m;

        vector<int> buf;
        buf.push_back(0);
        vector<int>::iterator it = buf.begin();

        string op;
        while(m-- > 0){
            cin >> op;
            if(op == "show"){
                cout << iton[*it] << endl;
            }else if(op == "back"){
                if(it != buf.begin())   it--;
            }else if(op == "forward"){
                it++;
                if(it == buf.end()) it--;
            }else if(op == "click"){
                cin >> w >> h;
                for(button b : v[*it]){
                    if(inRange(w, b.a[0], b.a[2]) && inRange(h, b.a[1], b.a[3])){
                        it++;
                        buf.erase(it, buf.end());
                        buf.push_back(ntoi[b.to]);
                        it = --buf.end();
                    }
                }
            }
        }

    }
    return 0;
}