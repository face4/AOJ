#include<iostream>
#include<map>
#include<set>
using namespace std;
typedef string::const_iterator State;

set<int> expression(State &begin);
set<int> term(State &begin);
set<int> factor(State &begin);
set<int> elem(State &begin);

map<char, set<int>> m;
set<int> all;

set<int> expression(State &begin){
    set<int> ret = term(begin);
    while(1){
        if(*begin == 'i'){
            begin++;
            set<int> tmp = term(begin), res;
            for(int val : ret)  if(tmp.count(val))  res.insert(val);
            ret = res;
        }else if(*begin == 'u'){
            begin++;
            set<int> tmp = term(begin);
            for(int val : tmp)  ret.insert(val);
        }else if(*begin == 'd'){
            begin++;
            set<int> tmp = term(begin), res;
            for(int val : ret)  if(tmp.count(val) == 0) res.insert(val);
            ret = res;
        }else if(*begin == 's'){
            begin++;
            set<int> tmp = term(begin), res;
            for(int val : ret)  if(tmp.count(val) == 0) res.insert(val);
            for(int val : tmp)  if(ret.count(val) == 0) res.insert(val);
            ret = res;
        }else{
            break;
        }
    }
    return ret;
}

set<int> term(State &begin){
    if(*begin == 'c'){
        begin++;
        set<int> tmp = factor(begin);
        set<int> ret;
        for(int x : all)    if(tmp.count(x) == 0)   ret.insert(x);
        return ret;
    }else{
        return factor(begin);
    }
}

set<int> factor(State &begin){
    if(*begin == '('){
        begin++;
        set<int> tmp = expression(begin);
        begin++;    // )
        return tmp;
    }else{
        return elem(begin);
    }
}

set<int> elem(State &begin){
    set<int> ret = m[*begin];
    begin++;
    return ret;
}

int main(){
    char c;
    int n;
    while(cin >> c >> n){
        m.clear();
        all.clear();
        while(c != 'R'){
            for(int i = 0; i < n; i++){
                int x;  cin >> x;
                m[c].insert(x);
                all.insert(x);
            }
            cin >> c >> n;
        }
        string s;
        cin >> s;
        State it = s.begin();
        set<int> res = expression(it);
        if(res.size()){
            for(set<int>::iterator it = res.begin(); it != res.end(); it++){
                if(it != res.begin())   cout << " ";
                cout << *it;
            }
            cout << endl;
        }else{
            cout << "NULL" << endl;
        }
    }
    return 0;
}