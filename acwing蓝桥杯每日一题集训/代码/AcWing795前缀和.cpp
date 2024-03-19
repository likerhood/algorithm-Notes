#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

const int N = 100005;
int n, q;
int e[N], sum[N];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> e[i];
        sum[i] = sum[i - 1] + e[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}
