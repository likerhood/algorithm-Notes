#include<bits/stdc++.h>
using namespace std;

const int N = 100020;
int n, m;
int a[N], fa[N], cnt[N];

void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        cnt[i] = 1;
    }
}

int find(int x){
    if(x != fa[x])  fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int i, int j){
    int x = find(i);
    int y = find(j);
    if(x != y){
        fa[x] = y;
        cnt[y] += cnt[x];
    }
}


int main(){
    cin >> n >> m;
    init();
    while(m--){
        string op;
        int x, y;
        cin >> op;
        if(op == "C"){
            cin >> x >> y;
            merge(x, y);
        }else if(op == "Q1"){
            cin >> x >> y;
            if(find(x) == find(y))  cout << "Yes" << endl;
            else                    cout << "No" << endl;
        }else if(op == "Q2"){
            cin >> x;
            cout << cnt[find(x)] << endl;
        }
    }
    return 0;
}