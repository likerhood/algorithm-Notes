#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int st[N];      // 模拟栈的数组
int top;

void init(){
    top = -1;
}

void push(int x){
    st[++top] = x;
}

void pop(){
    top--;
}

bool empty(){
    return top == -1;
}

int query(){
    return st[top];
}

int main(){

    int n;
    cin >> n;
    init();
    while(n--){
        string op;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            push(x);
        }else if(op == "pop"){
            pop();
        }else if(op == "empty"){
            if(empty())     cout << "YES" << endl;
            else            cout << "NO" << endl;
        }else if(op == "query"){
            cout << query() << endl;
        }
    }
    return 0;
}