#include<iostream>
using namespace std;

const int N = 1010;
int e[N][N], b[N][N];
int n, m, k;

void add(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){  
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> e[i][j];
            add(i, j, i, j, e[i][j]);
        }
    
    while(k--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        add(x1, y1, x2, y2, c);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            e[i][j] = e[i - 1][j] + e[i][j - 1] - e[i - 1][j - 1] + b[i][j];
            cout << e[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}