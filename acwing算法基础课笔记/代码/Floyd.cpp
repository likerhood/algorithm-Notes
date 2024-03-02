#include<bits/stdc++.h>
using namespace std;

const int N = 210, INF = 1e9;
int n, m, k;
int e[N][N];

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
}

int main(){

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)  e[i][j] = 0;
            else        e[i][j] = INF;
        }
    }

    while(m--){
        int a, b, x;
        cin >> a >> b >> x;
        e[a][b] = min(e[a][b], x);
    }

    floyd();

    while(k--){
        int x, y;
        cin >> x >> y;
        if(e[x][y] > INF / 2)   cout << "impossible" << endl;
        else                    cout << e[x][y] << endl;
    }
    
    return 0;
}