#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n;
int a[N], b[N], p[N], c[N];
int MOD = 99999997;
int tmp[N];
long long res;

void work(int a[]){

    for(int i = 1; i <= n; i++) p[i] = a[i];

    sort(p + 1, p + 1 + n);

    for(int i = 1; i <= n; i++){
        int l = 1, r = n;
        while(l < r){
            int mid = (r - l) / 2 + l;
            if(a[i] <= p[mid])  r = mid;
            else                l = mid + 1;
        }
        a[i] = l;
    }

}


void merge_sort(int l, int r){
    if(l >= r)  return;

    int mid = (r - l) / 2 + l;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r){
        if(b[i] <= b[j])    tmp[k++] = b[i++];
        else{
            tmp[k++] = b[j++];
            res += mid - i + 1;
            res %= MOD;
        }
    }

    while(i <= mid) tmp[k++] = b[i++];
    while (j <= r)  tmp[k++] = b[j++];

    for(int i = 0; i < k; i++)
        b[l++] = tmp[i];
    
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    work(a), work(b);
    for(int i = 1; i <= n; i++) c[a[i]] = i;
    for(int i = 1; i <= n; i++) b[i] = c[b[i]];

    // 求逆序对
    merge_sort(1, n);
    cout << res << endl;

    return 0;
}