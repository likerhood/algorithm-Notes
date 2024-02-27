#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int h[N], r;

// 下滤
void down(int u){
    int t = u;
    if(2*u <= r && h[t] > h[2*u])   t = 2*u;
    if(2*u + 1 <= r && h[t] > h[2*u + 1])   t = 2*u + 1;
    if(u != t){
        swap(h[u], h[t]);
        down(t);
    }
}

// 上滤
void up(int u){
    if(u/2  && h[u] < h[u/2]){
        swap(h[u], h[u/2]);
        up(u/2);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> h[i];
    r = n;

    // 建堆
    for(int i = r / 2; i; i--)  down(i);
    // 输出有序元素
    while(m--){
        cout << h[1] << ' ';
        swap(h[1], h[r]), r--, down(1);
    }

    return 0;
}