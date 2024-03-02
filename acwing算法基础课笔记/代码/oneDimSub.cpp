#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m;
int a[N], b[N];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    while(m--){
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }

    for(int i = 1; i <= n; i++){
        a[i] = a[i - 1] + b[i];
        cout << a[i] << ' ';
    }
    return 0;
}