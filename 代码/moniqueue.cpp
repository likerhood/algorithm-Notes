#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int q[N];       //队列
int hh, tt;

void init(){
    hh = 0;
    tt = -1;
}

void push(int x){
    q[++tt] = x;
}

void pop(){
    hh++;
}

bool empty(){
    return hh > tt;
}

int query(){
    return q[hh];
}

int main(){
    int n;
    cin >> n;
    init();
    while(n--){
        string s;
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            push(x);
        }else if(s == "pop"){
            pop();
        }else if(s == "empty"){
            if(empty()){
                cout << "YES" << endl;;
            }else{
                cout << "NO" << endl;;
            }
        }else if(s == "query"){
            cout << query() << endl;
        }
    }
    return 0;
}
