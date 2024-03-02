#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
vector<int> e[N];           // 邻接表
bool path[N];               // 标记是否访问过
int n;
int ans = INT_MAX;

int dfs(int u){

    int sum = 1;        // u节点的所有子树的所有结点数量
    int res = 0;        // 删掉u结点的话，剩余各个连通块中点数的最大值
    path[u] = true;

    for(int i = 0; i < e[u].size(); i++){
        int node = e[u][i];
        if(path[node] == false){
            int t = dfs(node);
            sum += t;
            res = max(res, t);
        }
    }

    res = max(res, n - sum);
    ans = min(ans, res);
    // cout << sum << ' ' << res << endl;
    return sum;

}


int main(){

    cin >> n;
    int m = n - 1;
    while(m--){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1);

    cout << ans;

    return 0;
}