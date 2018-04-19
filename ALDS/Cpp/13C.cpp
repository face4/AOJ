#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

struct Node {
    int key;
    Node *next, *prev;
};

Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
}

Node* listSearch(int key){
    Node* cur = nil->next;
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }
    return cur;
}

void printList(){
    Node* cur = nil->next;
    int isFirst = 0;
    while(1){
        if(cur == nil) break;
        if(isFirst++ > 0)   printf(" ");
        printf("%d" , cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void insert(int key){
    Node* x = (Node *)malloc(sizeof(Node));
    x->key = key;
    
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

void deleteNode(Node* del){
    if(del == nil) return;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

int main(){
    char op[20];
    int key, n, i;

    scanf("%d", &n);
    init();
    for(i = 0; i < n; i++){
        scanf("%s%d" , op , &key);
        if(op[0] == 'i'){
            insert(key);
        }else if(op[0] == 'd'){
            if(strlen(op) > 6){
                if(op[6] == 'F'){
                    deleteFirst();
                }else if(op[6] == 'L'){
                    deleteLast();
                }
            }else{
                deleteKey(key);
            }
        }
    }

    printList();

    return 0;
}