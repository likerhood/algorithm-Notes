#include<bits/stdc++.h>

using namespace std;
int n;
const int N = 100005;
int a[N], tmp[N];

void merge_sort(int l, int r){
    // 递归边界
    if(l >= r)  return;

    // 子任务分界点
    int mid = l + r >> 1;
    // 先处理子任务
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    // 处理完子任务对现阶段子任务进行处理
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] < a[j])
            tmp[k++] = a[i++];
        else    
            tmp[k++] = a[j++];
    }
    while(i <= mid){
        tmp[k++] = a[i++];
    }
    while(j <= r){
        tmp[k++] = a[j++];
    }
    // 注意放回到原数组
    for(int x = 0; x < k; x++){
        a[l++] = tmp[x];
    }

}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    merge_sort(0, n - 1);
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}