#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int e[N], l[N], r[N];       // 链表
int idx;                    // 存放结点的数组下标

void init(){
    r[0] = 1, l[1] = 0;     // 初始化头节点和尾结点
    idx = 2;                // 已经有两个结点了
}

void add(int k, int x){     // 在下标为k的结点后面插入新节点x
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}


int main(){

    int n;
    cin >> n;
    init();
    while(n--){
        string op;
        cin >> op;
        if(op == "L"){
            int x;
            cin >> x;
            add(0, x);
        }else if(op == "R"){
            int x;
            cin >> x;
            add(l[1], x);
        }else if(op == "D"){
            int k;
            cin >> k;
            remove(k + 1);
        }else if(op == "IL"){
            int k, x;
            cin >> k >> x;
            add(l[k + 1], x);
        }else if(op == "IR"){
            int k, x;
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for(int i = r[0]; i != 1; i = r[i]){
        cout << e[i] << ' ';
    }
    return 0;
}