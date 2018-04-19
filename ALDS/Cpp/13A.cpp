#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

int top, S[200];

bool isFull(){
    return top == 200;
}

bool isEmpty(){
    return top == 0;
}

void push(int x){
    top++;
    S[top] = x;
}

int pop(){
    return S[top--];
}

int main(){
    int a,b;
    top = 0;
    char s[100];
    while( scanf("%s", s) != EOF){
        if(s[0]  == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }else if(s[0] == '-'){
            a = pop();
            b = pop();
            push(b-a);
        }else if(s[0] == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }else{
            push(atoi(s));
        }
    }

    printf("%d\n", pop());

    return 0;
}