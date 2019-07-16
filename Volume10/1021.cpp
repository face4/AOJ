#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    vector<string> v(101, "");
    int len = 0;
    while(getline(cin, s), s != "END_OF_TEXT"){
        v[len++] = s;
    }
    string buf = "";
    int i = 0, j = 0;
    char com;
    while(cin >> com, com != '-'){
        if(com == 'a'){
            j = 0;
        }else if(com == 'e'){
            j = v[i].size();
        }else if(com == 'p'){
            if(i){
                i--;
            }
            j = 0;
        }else if(com == 'n'){
            if(i+1 < len){
                i++;
            }
            j = 0;
        }else if(com == 'f'){
            if(j < v[i].size()){
                j++;
            }else if(i+1 < len){
                i++;
                j = 0;
            }
        }else if(com == 'b'){
            if(j != 0){
                j--;
            }else if(i){
                i--;
                j = v[i].size();
            }
        }else if(com == 'd'){
            if(j < v[i].size()){
                v[i] = v[i].substr(0, j) + v[i].substr(j+1);
            }else if(i+1 < len){
                v[i] += v[i+1];
                len--;
                for(int k = i+1; k < len; k++)  v[k] = v[k+1];
            }
        }else if(com == 'k'){
            if(j < v[i].size()){
                buf = v[i].substr(j);
                v[i] = v[i].substr(0, j);
            }else if(i+1 < len){
                buf = "---";
                v[i] += v[i+1];
                len--;
                for(int k = i+1; k < len; k++)  v[k] = v[k+1];
            }
        }else if(com == 'y'){
            if(buf == ""){
                // do nothing.
            }else if(buf == "---"){
                string line = v[i].substr(j);
                v[i] = v[i].substr(0, j);
                len++;
                for(int k = len-1; k > i; k--)    v[k] = v[k-1];
                v[i+1] = line;
                i++;
                j = 0;
            }else{
                v[i] = v[i].substr(0, j) + buf + v[i].substr(j);
                j += buf.size();
            }
        }
    }
    for(int i = 0; i < len; i++)    cout << v[i] << endl;
    return 0;
}