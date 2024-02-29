// 由于这个题目中给出的图一个稠密图，所以直接用邻接表实现
// 朴素算法是没有使用堆优化的算法，时间复杂度为O(n^2)
#include<bits/stdc++.h>
using namespace std;

const int N = 510;
int e[N][N];        // 存储有向图
int d[N], vis[N];   // 存储各个结点的最短路径和是否访问过该节点

int n, m;

int dijkstra(int s){

    // 初始化原始距离
    for(int i = 1; i <= n; i++) d[i] = INT_MAX;
    d[s] = 0;

    // 开始 n - 1次遍历
    for(int i = 1; i < n; i++){

        // 找到n个结点中距离最短的点——贪心
        int t = -1;
        for(int j = 1; j <= n; j++){
            // 要求j结点没有呗访问过
            if(vis[j] == 0 && (t == -1 || d[t] > d[j])){
                t = j;
                // vis[j] = true;
            }
        }

        // 标记选择结点应该在遍历出最短那个结点之后
        vis[t] = 1; 

        // 松弛操作，更新选中结点的连接点
        for(int k = 1; k <= n; k++){
            if(e[t][k] != 0){
                d[k] = min(d[k], d[t] + e[t][k]);
            }
        }
    }
    if(d[n] == INT_MAX) return -1;
    return d[n];

}


int main(){
    cin >> n >> m;
    while(m--){
        int a, b, x;
        cin >> a >> b >> x;
        if(e[a][b] == 0 || e[a][b] > x)    e[a][b] = x;
    }


    cout << dijkstra(1) << endl;
    return 0;
}