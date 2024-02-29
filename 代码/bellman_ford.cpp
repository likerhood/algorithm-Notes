#include<bits/stdc++.h>
using namespace std;

const int N = 510, M = 10010;
int n, m, k;
struct Edges{
    int a, b, w;
}e[M];
int d[N], backup[N];           // 记录最短路径的数组

bool bellman_ford(int s){

    // 初始化d[]数组
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    for(int i = 0; i < k; i++){     // 最多遍历k次
        // 先拷贝上次的d[]数组，以免出现串联的情况
        memcpy(backup, d, sizeof d);
        // 每次遍历所有边
        for(int j = 0; j < m; j++){
            int a = e[j].a, b = e[j].b, w = e[j].w;
            d[b] = min(d[b], backup[a] + w);
            //使用backup:避免给a更新后立马更新b, 这样b一次性最短路径就多了两条边出来
        }

    }

    if(d[n] > 0x3f3f3f3f / 2)   return false;
    return true;
}


int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b, w};
    }

    bool res = bellman_ford(1);
    if(res == false)    cout << "impossible" << endl;
    else            cout << d[n] << endl;

    return 0;
}