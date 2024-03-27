#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 200005;
int n, q[N], tr[N];
LL resV, resA;

int lowbit(int x){
    return x & -x;
}

void add(int x, int k){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += k;
}

int query(int x){
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i))   res += tr[i];
    return res;
}


int main(){

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> q[i];

    for(int i = 1; i <= n; i++){
        int lowL = query(q[i]);
        resA += (LL) lowL * (q[i] - lowL - 1);
        int bigL = i - lowL - 1;
        resV += (LL) bigL * (n - q[i] - bigL);

        // 更新tr数组
        add(q[i], 1);
    }
 
    cout << resV << " " << resA << endl;
    return 0;
}