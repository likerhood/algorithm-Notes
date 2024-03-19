# 前缀和
[TOC]

## 1. 算法综述
前缀和的主要用途是在`O(1)`的时间复杂度中求出一段区间的总和。一维序列的前缀和相当于数列的前n项和，二维数组的前缀和可以用画图的方式辅助理解。注意在初始化前缀和时，边界部分都初始化为0，而且存储数值从下标1开始。

## 2. 题目练习
### 2.1 AcWing 562. 壁画
> [AcWing 562. 壁画](https://www.acwing.com/problem/content/564/)
> ![alt text](img/image-23.png)
> ![alt text](img/image-24.png)

思路：一个比较简单的思维题目——本质是要求你算出一段序列中固定大小的滑动窗口的区间和最大值，跟二分的最后一个题目差不多，利用前缀和和双指针就可以求出最大值。

代码：
```c++
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e6+10;
int t, n;
int e[N], sum[N];

int main(){
    cin >> t;
    int num = 0;
    while(t--){
        cin >> n;
        num++;
        string tmp;
        cin >> tmp;
        for(int i = 0; i <= n; i++){
            e[i + 1] = tmp[i] - '0'; 
        }

        int cnt = n % 2 == 1 ? n / 2 + 1 : n / 2;
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + e[i];
        }

        int res = -1;
        for(int i = 1, j = cnt; j <= n; j++, i++){
            int s = sum[j] - sum[i - 1];
            res = max(res, s);
        }
        cout << "Case #" << num << ": " << res << endl;
    }
    return 0;
}
```


### 2.2 AcWing 795. 前缀和
> [AcWing 795. 前缀和](https://www.acwing.com/problem/content/797/)
> ![alt text](img/image-25.png)

思路：模板题目，直接使用前缀和计算即可。

代码：
```c++
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

const int N = 100005;
int n, q;
int e[N], sum[N];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> e[i];
        sum[i] = sum[i - 1] + e[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}

```

### 2.3 AcWing 796. 子矩阵的和
> [AcWing 796. 子矩阵的和](https://www.acwing.com/problem/content/798/)
> ![alt text](img/image-26.png)

思路：二维前缀和的模板题，根据定义来计算即可。

代码：
```c++
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

const int N = 1005;
int n, m, q;
int e[N][N], sum[N][N];

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> e[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + e[i][j];
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int s = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
        cout << s << endl;
    }
    return 0;
}

```


### 2.4 AcWing 1230. K倍区间
> [AcWing 1230. K倍区间](https://www.acwing.com/problem/content/1232/)
> ![alt text](img/image-28.png)

