#include<bits/stdc++.h>
using namespace std;

const int N = 50020;
int n, k;               // 动物编号、询问次数
int fa[N], d[N];      // 祖先节点、举例祖先节点的路径（带权）

int find(int x){    // 寻找父节点
    if(x != fa[x]){
        int u = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = u;
    }
    return fa[x];
}

int main(){
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) fa[i] = i;
    int res = 0;                    
    while(k--){
        int c, x, y;
        cin >> c >> x >> y;
        if(x > n || y > n)  res++;
        else{
            int fx = find(x), fy = find(y);
            if(c == 1){
                if(fx == fy && (d[x] - d[y]) % 3 != 0)  res++;
                else if(fx != fy){
                    fa[fx] = fy;
                    d[fx] = d[y] - d[x];
                }
            }else{
                if(fx == fy && (d[x] - d[y] - 1) % 3 != 0) res++;
                else if(fx != fy){
                    fa[fx] = fy;
                    d[fx] = d[y] - d[x] + 1;
                }
            }
        }

    }

    cout << res;
    
    return 0;
}