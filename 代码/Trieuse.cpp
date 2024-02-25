#include<bits/stdc++.h>
using namespace std;

const int N = 100020, M = N * 31;
int a[N];
int son[M][2], idx;



void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int t = x >> i & 1;
        if(!son[p][t])    son[p][t] = ++idx;
        p = son[p][t];
    }
}

int query(int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--){
        int t = x >> i & 1;
        if(son[p][!t]){
            p = son[p][!t];
            res = res * 2 + !t;
        }else{
            p = son[p][t];
            res = res * 2 + t;
        }
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> a[i];

    int res = 0;
    for(int i = 0; i < n; i++){
        insert(a[i]);           // 插入Trie树
        res = max(query(a[i]) ^ a[i], res);            // 查询a[i]对应的异或值最大的结果
    }

    cout << res << endl;
    return 0;
}