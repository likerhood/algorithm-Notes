#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
int n, m;
vector<PII> e[N];
int d[N];

void spfa(){
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    queue<PII> que;
    que.push({1, 0});

    while(que.size()){
        PII tmp = que.front();
        que.pop();

        int u = tmp.first, w = tmp.second;
        for(auto x : e[u]){
            int xx = x.first, ww = x.second;
            if(d[xx] > d[u] + ww){
                d[xx] = d[u] + ww;
                que.push({xx, d[xx]});
            }
        }
    }
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        e[a].push_back({b, x});
    }

    spfa();
    
    if(d[n] == 0x3f3f3f3f)  cout << "impossible" << endl;
    else cout << d[n] << endl;
    return 0;
}