#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int head, idx;      // 头指针和当前可以存放结点下标的位置
int e[N], ne[N];    // 存放结点的数组和存放下一个指针的数组
void init(){
    head = -1;      // 当前头指针没有指向任何结点
    idx = 0;        //idx下标为0
}

void addToHead(int x){  // 在链表头部插入结点
    e[idx] = x;         // 1.创建和存放当前结点
    ne[idx] = head;     // 2.当前结点的下一个结点设置为头指针，头指针存放的是上一任头指针的下标
    head = idx;         // 3.更新头指针，存放新的头节点的下标
    idx++;              // 4.idx右移
}


void add(int k, int x){ // 在k下标后面加入新节点
    e[idx] = x;         // 1.创建和存放当前结点    
    ne[idx] = ne[k];    // 2.新节点的下一个结点位置为k结点下一个结点的位置
    ne[k] = idx;        // 3.更新k结点的下一个结点的位置
    idx++;              // 4.更新idx
}

void remove(int k){
    if(ne[k] == -1) return;
    ne[k] = ne[ne[k]];
}

int main(){
    init();
    int m;
    cin >> m;
    while(m--){
        char c;
        cin >> c;
        if(c == 'H'){
            int x;
            cin >> x;
            addToHead(x);
        }else if(c == 'D'){
            int k;
            cin >> k;
            if(k == 0)  head = ne[head];
            else        remove(k - 1);
        }else if(c == 'I'){
            int k, x;
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for(int i = head; i != -1; i = ne[i]){
        cout << e[i] << ' ';
    }

    return 0;
}