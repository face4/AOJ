#include<iostream>
#include<cfloat>
#include<cmath>
using namespace std;

int hexToDec(char x){
    if('0' <= x && x <= '9'){
        return x-'0';
    }else{
        return 10 + (x - 'a');
    }
}

int data[8][3] = { {0, 0, 0}   , 
                   {0, 0, 255} , 
                   {0, 255, 0} ,
                   {0, 255, 255} , 
                   {255, 0, 0} , 
                   {255, 0, 255} ,
                   {255, 255, 0} , 
                   {255, 255, 255}};

string color[8] = {"black", "blue", "lime", "aqua", "red", "fuchsia", "yellow", "white"};

int main(){
    while(1){
        string s;
        cin >> s;

        if(s == "0")    break;
    
        int r, g, b;
        r = 16 * hexToDec(s[1]) + hexToDec(s[2]);
        g = 16 * hexToDec(s[3]) + hexToDec(s[4]);
        b = 16 * hexToDec(s[5]) + hexToDec(s[6]);

        double dist = DBL_MAX;
        int ans;

        for(int i = 0; i < 8; i++){
            double tmp = sqrt(pow(r - data[i][0], 2.0) + pow(g - data[i][1], 2.0) + pow(b - data[i][2], 2.0));
            if(tmp < dist){
                dist = tmp;
                ans = i;
            }
        }

        cout << color[ans] << endl;
    }

    return 0;
}