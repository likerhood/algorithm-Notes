#include<iostream>

using namespace std;
const int N = 505;
typedef long long LL;
int n, m, k;
int s[N][N];

int main(){

    cin >> n >> m >> k;
    int tmp = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> tmp;
            s[i][j] = s[i - 1][j] + tmp;
        }

    LL res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int sum = 0;
            for(int l = 1, r = 1; r <= m; r++){
                sum += s[j][r] - s[i - 1][r];
                while(sum > k){
                    sum -= s[j][l] - s[i - 1][l];
                    l++;
                }
                if(sum <= k)    res += r - l + 1;
            }
        }
    }

    cout << res << endl;
    
    return 0;
}