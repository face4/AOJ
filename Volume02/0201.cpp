// 最初に購入価格が提示されたアイテムしかレシピには登場しないので、
// judgeもcountもいらない.ただの杞憂.

#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0)  break;

        map<string, int> table;

        string s;
        int p;

        for(int i = 0; i < n; i++){
            cin >> s >> p;
            table[s] = p;
        }

        int m;
        cin >> m;

        map<string, set<string>> recipe;
        for(int i = 0; i < m; i++){
            cin >> s >> p;
            string ingre;
            for(int i = 0; i < p; i++){
                cin >> ingre;
                recipe[s].insert(ingre);
            }
        }

        bool update = true;
        while(update){
            update = false;
            for(pair<string, set<string>> re : recipe){
                int cost = 0;
                bool judge = true;

                for(string x : re.second){
                    if(table.count(x) == 0){
                        judge = false;
                        break;
                    }
                    cost += table[x];
                }

                if(judge && 
                    (table.count(re.first) == 0 || table[re.first] > cost)){
                        update = true;
                        table[re.first] = cost;
                }

            }
        }

        string t;
        cin >> t;

        cout << table[t] << endl;
    }

    return 0;
}