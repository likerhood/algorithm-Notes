#include<iostream>
using namespace std;

typedef long long ll;
const int N = 1000010;
int n, m;
int  a[N], d[N], s[N], t[N];
ll b[N];

// 检查前mid个订单是否出现问题
bool check(int mid){
    // 进行当前mid个订单操作
    // 每次要对差分数组更新
    // 求差分数组
    for(int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
    for(int i = 1; i <= mid; i++){
        b[s[i]] -= d[i];
        b[t[i] + 1] += d[i];
    }

    // 检查n天中是否出现有问题的时间
    for(int i = 1; i <= n; i++){
        b[i] += b[i - 1];
        if(b[i] < 0)   return true;
    }

    return false;
}

int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> d[i] >> s[i] >> t[i];

    // 二分求订单号
    int l = 1,  r = m;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }   
    }

    if(check(l)){
        cout << -1 <<endl;
        cout << l << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}