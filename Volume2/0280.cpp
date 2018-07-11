#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        
        if(n == 0)  break;
        
        vector<int> person(n, 0);
        int turn = 0, ba = 0;
        
        char c;
        for(int i = 0; i < 100; i++){
            cin >> c;
            if(c == 'M')        person[turn]++;
            else if(c == 'S')   ba += person[turn]+1, person[turn] = 0;
            else if(c == 'L')   person[turn] += ba+1, ba = 0;
            turn = (turn+1)%n;
        }
        
        sort(person.begin(), person.end());
        for(int i = 0; i < n; i++){
            cout << person[i] << " ";
        }
        
        cout << ba << endl;
    }
    return 0;
}
