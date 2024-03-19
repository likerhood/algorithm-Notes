#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 100005;
typedef long long LL;
int n;
LL m;
int A[N], B[N];

bool check(int x){
    LL res = 0;
    for(int i = 0; i < n; i++){
        if(A[i] >= x){
            res += (A[i] - x) / B[i] + 1;
        }
    }

    return res >= m;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i];
    }

    int l = 0, r = 1e6 + 1;
    while(l < r){
        int mid = (LL) l + r + 1 >> 1;
        if(check(mid))  l = mid;
        else            r = mid - 1;
    }

    LL res = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(A[i] >= r){
            int c = (A[i] - r) / B[i] + 1;
            int ed = A[i] - B[i] * (c - 1);
            cnt += c;
            res += (LL) (A[i] + ed) * c / 2;
        }
    }

    cout << res - (cnt - m) * r ;

    return 0;
}