#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<string> a(k), b(k);
    for(int i = 0; i < k; i++)  cin >> a[i];
    for(int i = 0; i < k; i++)  cin >> b[i];
    int iso = 0, nak = 0;
    for(int i = 0; i < k; i++){
        int isobad = (iso==0&&a[i][0]=='k');
        int nakbad = (nak==0&&b[i][0]=='k');
        if(isobad+nakbad == 1){
            cout << (isobad ? "Nakajima" : "Isono") << "-kun" << endl;
            return 0;
        }else if(isobad+nakbad == 2){
            iso = nak = 0;
        }else{
            if(a[i][0]=='k' && b[i][0]=='k'){
                if(iso==nak){
                    iso = nak = 0;
                }else{
                    cout << (iso > nak ? "Isono" : "Nakajima") << "-kun" << endl;
                    return 0;
                }
            }else if(a[i][0]=='k'){
                if(iso==5 || b[i][0]=='t'){
                    cout << "Isono-kun" << endl;
                    return 0;
                }else{
                    iso = 0;
                }
            }else if(b[i][0]=='k'){
                if(nak==5 || a[i][0]=='t'){
                    cout << "Nakajima-kun" << endl;
                    return 0;
                }else{
                    nak = 0;
                }
            }else{
                if(a[i][0]=='t')    iso++;
                if(b[i][0]=='t')    nak++;
                if(iso > 5) iso = 5;
                if(nak > 5) nak = 5;
            }
        }
    }
    cout << "Hikiwake-kun" << endl;
    return 0;
}