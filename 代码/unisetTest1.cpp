#include<bits/stdc++.h>
using namespace std;

const int N = 100020;
int n, m;
int a[N], fa[N];

// 初始化并查集
void init(){
    for(int i = 1; i <= n; i++)
        fa[i] = i;
}

// 返回元素的祖先节点
int find(int x){
    if(x != fa[x])  fa[x] = find(fa[x]);
    return fa[x];
}

// 合并两个元素或者集合
void merge(int i, int j){
    int x = find(i);
    int y = find(j);
    fa[x] = y;
}

int main(){
    
    cin >> n >> m;
    init();
    while(m--){
        string op;
        int x, y;
        cin >> op;
        if(op == "M"){
            cin >> x >> y;
            merge(x, y);
        }else if(op == "Q"){
            cin >> x >> y;
            if(find(x) == find(y))  cout << "Yes" << endl;
            else                    cout << "No" << endl;
        }
    }
    return 0;
}