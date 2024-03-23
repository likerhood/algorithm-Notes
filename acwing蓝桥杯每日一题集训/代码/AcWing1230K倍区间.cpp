#include<iostream>
using namespace std;

typedef long long LL;
const int N = 100005;
LL sum[N];
int n, k;
int e[N];     
LL cnt[N], num[N];  // 记录余数和i结尾的区间个数

int main(){

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> e[i];
        sum[i] = sum[i - 1] + e[i];
    }

    for(int i = 1; i <= n; i++){
        num[i] += cnt[sum[i] % k];
        cnt[sum[i] % k]++;
    }

    LL res = 0;
    for(int i = 1; i <= n; i++){
        res += num[i];
    }

    cout << res + cnt[0] << endl;

    return 0;
}