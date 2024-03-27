#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 100005;
int n, m;
int a[N];
LL tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int k){
    for(int i = x; i <= n; i += lowbit(i))  tr[i] += k;
}

LL sum(int x){
    LL res = 0;
    for(int i = x; i > 0; i -= lowbit(i))   res += tr[i];
    return res;
}

int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) add(i, a[i] - a[i  - 1]);

    while(m--){
        string op;
        cin >> op;
        if(op == "Q"){
            int t;
            cin >> t;
            cout << sum(t) << endl;
        }else{
            int x, y, z;
            cin >> x >> y >> z;
            add(x, z), add(y + 1, -z);
        }
    }
    
    return 0;
}