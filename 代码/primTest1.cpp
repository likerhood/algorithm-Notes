#include<bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int e[N][N];    // 邻接矩阵
int d[N];       // 当前结点到集合的最短距离
bool vis[N];    // 判断该节点是否被访问过

int prim(int s){
    // 初始化
    memset(d, 0x3f, sizeof d);
    d[s] = 0;

    // 记录生成树的权值之和
    int res = 0;

    // 遍历n次
    for(int i = 0; i < n; i++){
        // 寻找需要加入集合的结点
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && (t == -1 || d[j] < d[t])){
                t = j;
            }
        }
        // 此时就会选出一个结点t
        // 标记该节点
        vis[t] = true;

        // 判断当前结点是否是孤立的，孤立的结点 d[t] = INF
        if(d[t] == INF)  return d[t];
        // 加上当前边
        res += d[t];

        // 根据当前t结点更新周围其他结点
        // 这里的更新和dijkstra算法不一样，它只需要比较当前结点可以遍历到的边的长度即可
        for(int j = 1; j <= n; j++){
            if(!vis[j] && d[j] > e[t][j]){
                d[j] = e[t][j];                 // 区别
            }
        }
    }

    return res;
}

int main(){
    
    cin >> n >> m;
    memset(e, 0x3f, sizeof e);
    
    while(m--){
        int a, b, x;
        cin >> a >> b >> x;
        e[a][b] = e[b][a] = min(e[a][b], x);
    }

    int t = prim(1);
    if(t >= INF)  cout << "impossible" << endl;
    else                cout << t << endl;
    return 0;
}