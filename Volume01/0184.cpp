#include<iostream>
using namespace std;

int classify(int age){
    if(age < 10)    return 0;
    if(age < 20)    return 1;
    if(age < 30)    return 2;
    if(age < 40)    return 3;
    if(age < 50)    return 4;
    if(age < 60)    return 5;
    return 6;
}

int main(){
    while(1){
        int n;
        cin >> n;

        if(n == 0)  break;

        int A[7] = {};

        while(n-- > 0){
            int age;
            cin >> age;
            A[classify(age)]++;
        }

        for(int x : A)  cout << x << endl;
    }
    return 0;
}