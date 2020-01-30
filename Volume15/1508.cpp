#include<iostream>
#include<random>
#include<vector>
#include<climits>
using namespace std;

// 0-indexed
template<class T, class F>
struct Treap{
    struct Node{
        T val, sum;
        int pri;
        int cnt;
        Node* ch[2];
        Node(T v, int p) : val(v), sum(v), pri(p){
            cnt = 1;
            ch[0] = ch[1] = NULL;
        }
    };

    Node* root;
    vector<T> v;
    F f;    
    T def;  
    Treap(T def, F f) : f(f), def(def) {
        root = NULL;
    }

    int count(Node* t)  {return t==NULL ? 0 : t->cnt;}
    T sum(Node* t)    {return t==NULL ? def : t->sum;}

    Node* update(Node* t){
        t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;
        t->sum = f(sum(t->ch[0]), f(t->val, sum(t->ch[1])));
        return t;
    }

    Node* rotate(Node* t, int b){
        Node* s = t->ch[b];
        t->ch[b] = s->ch[1-b];
        s->ch[1-b] = t;
        update(t);
        update(s);
        return s;
    }

    Node* insert(Node* t, int k, T val, int pri){
        if(t == NULL)   return new Node(val, pri);
        int leftCnt = count(t->ch[0]);
        int b = k > leftCnt;
        t->ch[b] = insert(t->ch[b], k-(b ? leftCnt+1 : 0), val, pri);
        update(t);
        if(t->ch[b]->pri > t->pri)  t = rotate(t, b);
        return t;
    }
    Node* insert_value(Node* t, T val, int pri){
        if(t == NULL)   return new Node(val, pri);
        int b = val > t->val;
        t->ch[b] = insert_value(t->ch[b], val, pri);
        update(t);
        if(t->ch[b]->pri > t->pri)  t = rotate(t, b);
        return t;
    }
    Node* erase(Node* t, int k, bool me=false){
        if(!me && count(t) <= k)   return t;    // out-of-range
        me |= count(t->ch[0])==k;
        if(me){
            if(t->ch[0]==NULL && t->ch[1]==NULL){
                delete t;
                return NULL;
            }
            int b = (t->ch[0]==NULL ? -1 : t->ch[0]->pri) < (t->ch[1]==NULL ? -1 : t->ch[1]->pri);
            t = rotate(t, b);
            t->ch[1-b] = erase(t->ch[1-b], k, me);
        }else{
            if(count(t->ch[0]) > k){
                t->ch[0] = erase(t->ch[0], k, me);
            }else{  // definitely count(t->ch[0]) < k
                t->ch[1] = erase(t->ch[1], k-count(t->ch[0])-1, me);
            }
        }
        return update(t);
    }
    Node* erase_value(Node* t, T val, bool me=false){
        if(t == NULL)   return NULL;    // there's no node whose value is val
        me |= t->val==val;
        if(me){
            if(t->ch[0]==NULL && t->ch[1]==NULL){
                delete t;
                return NULL;
            }
            int b = (t->ch[0]==NULL ? -1 : t->ch[0]->pri) < (t->ch[1]==NULL ? -1 : t->ch[1]->pri);
            t = rotate(t, b);
            t->ch[1-b] = erase_value(t->ch[1-b], val, me);
        }else{
            if(val < t->val){
                t->ch[0] = erase_value(t->ch[0], val, me);
            }else{
                t->ch[1] = erase_value(t->ch[1], val, me);
            }
        }
        return update(t);
    }

    Node* merge(Node* l, Node* r){
        Node* tmp = new Node(def, INT_MAX);    // rand()は環境依存
        tmp->ch[0] = l;
        tmp->ch[1] = r;
        update(tmp);
        bool me = true;
        return erase(tmp, -1, me);
    }

    // [0, k), [k, n)
    pair<Node*, Node*> split(int k){
        root = insert(root, k, def, INT_MAX);
        return make_pair(root->ch[0], root->ch[1]);
    }

    T get(Node* t, int k){
        int leftCnt = count(t->ch[0]);
        if(leftCnt > k)     return get(t->ch[0], k);
        if(leftCnt == k)    return t->val;
        return get(t->ch[1], k-1-leftCnt);
    }

    void set(Node* t, int k, T newVal){
        if(k < count(t->ch[0])){
            set(t->ch[0], k, newVal);
        }else if(k == count(t->ch[0])){
            t->val = newVal; // or f(t->val, newVal) //
        }else if(k > count(t->ch[0])){
            set(t->ch[1], k-count(t->ch[0])-1, newVal);
        }
        update(t);
    }

    // a, bはt-oriented
    T query(Node* t, int a, int b){
        if(t == NULL)   return def;
        if(a == 0 && count(t) <= b+1)   return t->sum;
        T ret = def;
        int leftCnt = count(t->ch[0]);
        if(a < leftCnt) ret = f(ret, query(t->ch[0], a, b));
        if(a <= leftCnt && leftCnt <= b)    ret = f(ret, t->val);
        if(b > leftCnt) ret = f(ret, query(t->ch[1], max(0, a-leftCnt-1), b-leftCnt-1));
        return ret;
    }

    Node* insert(int k, T val){
        return root = insert(root, k, val, rand());
    }
    Node* erase(int k){
        return root = erase(root, k);
    }
    T get(int k){
        return get(root, k);
    }
    void set(int k, T val){
        set(root, k, val);
    }
    T query(int a, int b){
        return query(root, a, b);
    }
    Node* insert_value(T val){
        return root = insert_value(root, val, rand());
    }
    Node* erase_value(T val){
        return root = erase_value(root, val);
    }
    void flatten(Node* t){
        if(t==NULL) return;
        if(t->ch[0] != NULL)    flatten(t->ch[0]);
        v.push_back(t->val);
        if(t->ch[1] != NULL)    flatten(t->ch[1]);
    }

    vector<T> flatten(){
        v.clear();
        flatten(root);
        return v;
    }
};

int main(){
    auto f = [](int x, int y)->int{
        return min(x, y);
    };
    Treap<int, decltype(f)> t(INT_MAX, f);
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        t.insert(i, a);
    }
    while(q--){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 0){
            int tmp = t.get(z);
            t.erase(z);
            t.insert(y, tmp);
        }else if(x == 1){
            printf("%d\n", t.query(y, z));
        }else if(x == 2){
            t.set(y, z);
        }
    }
    return 0;
}
