#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
typedef long long ll;
int e[N], b[N], cnt[N];
int n, m;

int main(){  
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> e[i];
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        b[l]++, b[r + 1]--;
    }

    for(int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + b[i];

    ll sumA = 0;
    for(int i = 1; i <= n; i++){
        sumA += (ll)e[i] * cnt[i];
    }

    sort(e, e + n + 1);
    sort(cnt, cnt + n + 1);
    
    ll sumB = 0;
    for(int i = 1; i <= n; i++){
        sumB += (ll)e[i] * cnt[i];
    }

    cout << sumB - sumA << endl;

    return 0;
}