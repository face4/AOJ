#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

struct data{
    int x1, y1, x2, y2;
};

vector<string> vs;
vector<data> vd;
vector<int> depth;
map<string, vector<string>> child;

void init(){
    vs.clear();
    vd.clear();
    depth.clear();
    child.clear();
}

string str(int &pos, string s){
    string ret = "";
    while(s[pos] != '>')    ret += s[pos++];
    return ret;
}

int num(int &pos, string s){
    int ret = 0;
    while(isdigit(s[pos]))  ret = ret*10+s[pos++]-'0';
    return ret;
}

// return : name of root panel
string build(int &pos, int dep, const string s){
    pos++;  // <
    string name = str(pos, s);
    pos++;  // >
    vs.push_back(name);
    int c[4];
    for(int i = 0; i < 4; i++){
        c[i] = num(pos, s);
        if(i != 3)  pos++;  // ,
    }
    vd.push_back(data({c[0], c[1], c[2], c[3]}));
    depth.push_back(dep);
    while(s[pos+1] != '/'){
        child[name].push_back(build(pos, dep+1, s));
    }
    while(pos < s.length() && s[pos] != '>')    pos++;
    pos++;  // >
    return name;
}

int getPanel(int x, int y){
    int ret = -1, tmpdep = -1;
    for(int i = 0; i < vd.size(); i++){
        if(!inRange(x, vd[i].x1, vd[i].x2) || !inRange(y, vd[i].y1, vd[i].y2))  continue;
        if(depth[i] > tmpdep){
            tmpdep = depth[i];
            ret = i;
        }
    }
    return ret;
}

int main(){
    int n;
    while(cin >> n, n){
        string s;
        cin >> s;
        int pos = 0;
        init();
        build(pos, 0, s);
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            int panel = getPanel(x, y);
            if(panel == -1){
                cout << "OUT OF MAIN PANEL 1" << endl;
                continue;
            }
            cout << vs[panel] << " " << (int)child[vs[panel]].size() << endl;
        }
    }
    return 0;
}