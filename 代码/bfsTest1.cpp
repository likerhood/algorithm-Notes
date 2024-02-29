#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 105;
int n, m;
int g[N][N], d[N][N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            cin >> g[i][j];
        
    queue<PII> que;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    que.push({0, 0});
    g[0][0] = 1;
    while(!que.empty()){
        PII tmp = que.front();
        que.pop();
        int x = tmp.first, y = tmp.second;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == 0){
                d[xx][yy] = d[x][y] + 1;
                g[xx][yy] = 1;
                que.push({xx, yy});
            }
        }
    }

    cout << d[n - 1][m - 1];
    return 0;
}