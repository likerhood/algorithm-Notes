#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
const int N = 100005;
int n;
LL m;
int a[N], b[N];
LL res;

bool check(int mid){

    LL cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] >= mid){
            cnt += (a[i] - mid) / b[i] + 1;
        }
    }

    return cnt >= m;
}

int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }

    int l = 0, r = 1e6 + 5;
    while(l < r){
        int mid = (LL) l + r + 1 >> 1;
        if(check(mid))  l = mid;
        else            r = mid - 1;
    }

    LL num = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] >= l){
            int cnt = (a[i] - l) / b[i] + 1;
            num += cnt;
            int ed = a[i] - (cnt - 1) * b[i];
            res += (LL) (a[i] + ed) * cnt / 2;
        }
    }

    cout << res - (num - m) * l << endl;


    return 0;
}