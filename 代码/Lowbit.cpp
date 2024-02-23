#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, a[N];
int lowbit(int n){
    return n & (-n);
}
int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int cnt = 0;
        while(a[i]){
            a[i] -= lowbit(a[i]);
            cnt++;
        }
        cout << cnt << ' ';
    }
    return 0;
}