#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int m, n;
    while(1){
        cin >> m >> n;
        if(m + n == 0)  break;

        vector<int> people;
        for(int i = 1; i <= m; i++) people.push_back(i);

        string x;
        bool freeze = false;
        int pos = 0;

        for(int num = 1; num <= n; num++){
            cin >> x;
            if(freeze)  continue;
            
            string answer = "";
            if(num % 3 == 0)    answer += "Fizz";
            if(num % 5 == 0)    answer += "Buzz";
            if(num % 3 != 0 && num % 5 != 0)    answer = to_string(num);

            if(x != answer){
                people.erase(people.begin() + pos);
                if(pos == people.size())    pos = 0;
                if(people.size() == 1)  freeze = true;
            }else{
                pos = (pos + 1) % people.size();
            }
        }

        for(int i = 0; i < people.size(); i++){
            if(i)   cout << " ";
            cout << people[i];
        }
        cout << endl;

    }
    return 0;
}