#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2010;
vector<PII> e[N];
int n, m;
int d[N], cnt[N];   // 记录最短路径和边长次数
bool vis[N];        // 记录结点是否入队

bool spfa(){

    queue<PII> que;
    for(int i = 1; i <= n; i++){    // 将所有结点全部加入队列
        que.push({i, 0});
        vis[i] = true;              // 同时标记已经入队
    }
        
    while(que.size()){              // 队列不为空时
        PII tmp = que.front();
        que.pop();
        vis[tmp.first] = false;     // 出队和标记

        int u = tmp.first;
        for(auto x : e[u]){         // 访问该节点的临界点，
            int t = x.first, w = x.second;
            if(d[t] > d[u] + w){    // 发现负权边胡总和负环，就会更新
                d[t] = d[u] + w;
                cnt[t] = cnt[u] + 1;    // 那么该节点的边数就是之前结点边数+1

                if(cnt[t] > n)  return true;    // 出现死循环，直接返回
                
                if(vis[t] == false){        // 如果没有入过队，那就入队
                    que.push({t, d[t]});
                    vis[t] = true;
                }
            }

        }
    }

    return false;


}

int main(){

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        e[a].push_back({b, x});
    }

    if(spfa())  cout << "Yes" << endl;
    else        cout << "No" << endl;
    return 0;
}