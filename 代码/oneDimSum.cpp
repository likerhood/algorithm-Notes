#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
int a[N], sum[N];
int l, r;

int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    while(m--){
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

    return 0;
}