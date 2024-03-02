// 由于这个题目中给出的图一个稠密图，所以直接用邻接表实现
// 朴素算法是没有使用堆优化的算法，时间复杂度为O(n^2)
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 150010;
vector<PII> e[N];        // 存储有向图,邻接表
int d[N], vis[N];   // 存储各个结点的最短路径和是否访问过该节点

int n, m;

int dijkstra(int s){

    // 初始化原始距离
    for(int i = 1; i <= n; i++) d[i] = INT_MAX;
    d[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> que; // 小根堆
    que.push({0, s});

    // 遍历优先队列的数据
    while(que.size()){
        PII tmp = que.top();
        que.pop();
        
        // 标记当前结点的编号
        int t = tmp.second;
        if(vis[t] == 1) continue;      // 当前结点是否访问过
        vis[t] = 1;                 // 标记当前结点

        for(auto x : e[t]){
            int u = x.second, w = x.first;
            if(d[u] > d[t] + w){
                // 更新最短路径
                d[u] = d[t] + w;
                // 最短路径入队
                que.push({d[u], u});
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
        e[a].push_back({x, b});
    }

    cout << dijkstra(1) << endl;
    // for(int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}