#include<bits/stdc++.h>

using namespace std;
const int N = 100005;
int n;
int a[N];

void quickSort(int l, int r){
    // 递归结束条件
    if(l >= r)  return;

    // 分治的分界点
    int tmp = a[ l + r >> 1];
    // 双指针
    int i = l - 1, j = r + 1;
   
    // 核心代码,楷书排序中分开前的处理
    while(i < j){
        do{ i++; } while (a[i] < tmp);
        do{ j--; } while (a[j] > tmp);
        if(i < j){
            swap(a[i], a[j]);
        }
    }

    // 递归处理分开的两段
    quickSort(l, j);
    quickSort(j + 1, r);

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(0, n - 1);
    
    for(int i = 0; i < n; i++){
        cout << a[i] <<' ';
    }
    return 0;
}