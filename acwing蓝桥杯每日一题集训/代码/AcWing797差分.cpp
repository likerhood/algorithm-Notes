#include<iostream>
using namespace std;

const int N = 100010;
int e[N], b[N];
int n, k;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> e[i];
        b[i] = e[i] - e[i - 1];
    }
    while(k--){
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }

    for(int i = 1; i <= n; i++){
        e[i] = e[i - 1] + b[i];
        cout << e[i] << ' ';
    }

    
    return 0;
}