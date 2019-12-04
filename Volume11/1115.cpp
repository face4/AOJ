#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h, c, w, space;
    while(scanf("%d\n", &h), h){
        scanf("%d\n%d\n%d\n", &c, &w, &space);
        
        string in = "";
        while(space--)  in += ".";

        string line;
        vector<string> v;
        while(getline(cin, line), line != "?"){
            int pos = 0;
            while(pos < line.length()){
                v.push_back(line.substr(pos, min((int)line.length()-pos, w)));
                pos += min((int)line.length()-pos, w);
            }
            if(pos == 0)    v.push_back("");
        }
        while(v.size()%(h*c))   v.push_back("");
        int pos = 0;
        while(pos < v.size()){
            for(int i = 0; i < h; i++){
                for(int j = 0; j < c; j++){
                    if(j)   cout << in;
                    cout << v[pos+j*h+i];
                    for(int k = 0; k < w-v[pos+j*h+i].length(); k++)    cout << ".";
                }
                cout << endl;
            }
            pos += h*c;
            cout << "#" << endl;
        }
        cout << "?" << endl;
    }
    return 0;
}