#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 5005;
int n, R;
int s[N][N];

int main(){

    cin >> n >> R;
    R = min(R, 5001);
    int x, y, w;
    for(int i = 1; i <= n; i++){
        cin >> x >> y >> w;
        x++, y++;
        s[x][y] += w;
    }

    for(int i = 1; i <= 5001; i++){
        for(int j = 1; j <= 5001; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
        }
    }

    int res = 0;
    for(int i = R; i <= 5001; i++){
        for(int j = R; j <= 5001; j++){
            res = max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);
        }
    }

    cout << res << endl;


    return 0;
}