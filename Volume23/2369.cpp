#include<iostream>
using namespace std;
string s;
bool m[500][500] = {}, v[500][500] = {};
bool f(int i, int j){
    if(v[i][j]) return m[i][j];
    v[i][j] = true;
    if(i >= j)  return m[i][j] = true;
    if(s[i] != 'm' || s[j] != 'w')  return m[i][j] = false;
    bool r = false;
    for(int k = i+1; k < j; k++){
        if(s[k] == 'e'){
            r |= (f(i+1, k-1)&&f(k+1, j-1));
        }
    }
    return m[i][j] = r;
}
int main(){
    cin >> s;
    cout << (f(0, s.length()-1) ? "Cat" : "Rabbit") << endl;
    return 0;
}