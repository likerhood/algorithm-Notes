#include<iostream>

using namespace std;

const int N = 100005;
int q[N], tmp[N];
int n;
long long res;

void merge_sort(int l, int r){
    if(l >= r)  return;

    int mid = (r - l) / 2 + l;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j])    tmp[k++] = q[i++];
        else{
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }

    while(i <= mid) tmp[k++] = q[i++];
    while (j <= r)  tmp[k++] = q[j++];

    for(int i = 0; i < k; i++)
        q[l++] = tmp[i];
    
}

int main(){

    cin >> n;
    for(int i = 0; i < n; i++)  cin >> q[i];

    merge_sort(0, n - 1);
    cout << res;

    return 0;
}