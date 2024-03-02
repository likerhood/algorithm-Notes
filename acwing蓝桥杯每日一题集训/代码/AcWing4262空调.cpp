#include<iostream>
using namespace std;

const int N = 100010;
int p[N], b[N], w[N];   // w[N]是差分数组
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >>p[i];
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        b[i] = t - p[i];
        w[i] = b[i] - b[i - 1];
    }

    // 求出正数和和负数和
    int pos = 0, neg = 0;
    for(int i = 1; i <= n; i++){
        if(w[i] > 0)    pos += w[i];
        else            neg += w[i]; 
    }

    cout << max(pos, abs(neg)) << endl;
    return 0;
}