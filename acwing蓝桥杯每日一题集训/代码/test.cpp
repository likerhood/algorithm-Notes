#include<iostream>
using namespace std;

typedef long long ll;
const int N = 100010;
int n, m;
int a[N], b[N];
int r = 0;

bool check(int mid){
    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += (ll) (a[i] / mid) * (b[i] / mid);
    }
    if(res >= m)    return true;
    else            return false;
}


int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        r = max(a[i], r);
        r = max(b[i], r);
    }

    int l = 1;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }

    cout << l << endl;
    
    return 0;
}