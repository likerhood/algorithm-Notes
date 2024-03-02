#include<iostream>
using namespace std;

const int N = 2010;
int e[N][N], b[N][N];
int n, m;

void add(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){  
    cin >> n >> m;
    while(m--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        add(x1, y1, x2, y2, 1);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            e[i][j] = e[i - 1][j] + e[i][j - 1] -e[i - 1][j - 1] + b[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(e[i][j] % 2 == 0)    cout << 0;
            else                    cout << 1;
        }
        cout << endl;
    }

    return 0;
}