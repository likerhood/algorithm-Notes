#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
vector<int> e[N];
bool g[N];

int bfs(int start){

    queue<pair<int, int>> que;
    que.push({start, 0});
    g[start] = true;
    while(!que.empty()){
        pair<int, int> tmp = que.front();
        que.pop();
        if(tmp.first == n)  return tmp.second;
        int x = tmp.first, dist = tmp.second;
        for(auto node : e[x]){
            if(g[node] == false){
                que.push({node, dist + 1});
                g[node] = true;
            }
        }

    }

    return -1;
}

int main(){

    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }

    cout << bfs(1);

    return 0;
}