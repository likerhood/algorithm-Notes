#include<iostream>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

const int N = 100005;
int n, m;
double e[N], sum[N];

bool check(double x){
    // 求前缀和
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + e[i] - x;
    }

    // 二分求满足条件的区间
    double minv = 1e9;
    for(int i = 1, j = m; j <= n; j++, i++){
        minv = min(minv, sum[i - 1]);
        if(sum[j] - minv >= 0)  return true;
    }
    return false;

}

int main(){

    cin >> n >> m;
   
    for(int i = 1; i <= n; i++){
        cin >> e[i];
    }
    
    // 二分
    double l = 0, r = 2000;
    while(r - l > 1e-5){
        double mid = (l + r) / 2;
        if(check(mid))  l = mid;
        else            r = mid;
    }

    cout << (int) (r * 1000) << endl;

    return 0;
}