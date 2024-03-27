#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 100005, M = 1000005;
int a[N], n;
LL tr[M], cnt[M];

int lowbit(int x){
    return x & -x;
}

void add(int x, int k){
    for(int i = x; i <= 1000000; i += lowbit(i))    tr[i] += k; 
}

int sum(int x){
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i))   res += tr[i];
    return res;
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]++;     // 避免为0
    }
    for(int i = 1; i <= n; i++){
        int lessL = sum(a[i]);
        int bigL = i - 1 - lessL;
        cnt[i] += bigL;
        add(a[i], 1);
    }

    memset(tr, 0, sizeof tr);

    for(int i = n; i > 0; i--){
        int lessL = sum(a[i] - 1);
        cnt[i] += lessL;
        add(a[i], 1);
    }

    LL res = 0;
    for(int i = 1; i <= n; i++){
        res += (1 + cnt[i]) * cnt[i] / 2;
    }

    cout << res << endl;
    
    return 0;
}