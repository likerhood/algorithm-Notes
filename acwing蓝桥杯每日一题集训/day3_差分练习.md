# 差分
[TOC]

## 1. 算法综述
差分算法是前缀和的逆运算。

差分算法可以实现在`O(1)`的时间复杂度下将一个序列的区间同时加减一个常数。如果差分数组全是0，那么原数组也全部都是0。二维差分数组就是先假设原数组都是0，然后根据差分算法的性质不断插入元素。

> [二维差分讲解博客](https://www.acwing.com/solution/content/27325/)
> ![alt text](img/image.png)
> ![alt text](img/image-1.png)


**一维差分模板：**
```c++
int e[N], b[N];
// 初始化
for(int i = 1; i <= n; i++){
    b[i] = e[i] - e[i - 1];
}
// 将区间[l, r] 加上 c
b[l] += c, b[r + 1] -= c;
// 求出改变后的序列
for(int i = 1; i <= n; i++){
    e[i] = e[i - 1] + b[i];
}
```

**二维差分模板：**
```c++
int e[N][N], b[N][N];
// 让矩阵(x1, y1)->(x2, y2) 都加上c
void add(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
// 初始化差分数组
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        cin >> c;
        add(i, j, i, j, x);
    }
}
// 让矩阵(x1, y1)->(x2, y2) 都加上c
add(x1, y1, x2, y2, c);
// 求出改变后的矩阵
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        // 相当于二维前缀和
        e[i][j] = e[i - 1][j] + e[i][j - 1] - e[i - 1][j - 1] + b[i][j];
    }
}
```

***
## 2. 题目练习
### 2.1 题目一：AcWing 4262. 空调
>[AcWing 4262. 空调](https://www.acwing.com/activity/content/problem/content/9710/)
>![alt text](img/image-2.png)
>![alt text](img/image-3.png)

思路：
就是将原序列的连续一段全部增加或者减少1，求出变成目标序列的最小操作数。

**题目要求同时将一段子数组全部加上1或者减去1, 考虑采用差分数组的思想**, 将原数组每一项的原始温度减去目标温度, 得到每一项需要改变的数值, 然后求出该数组的差分数组, **目标是使得差分数组的每一项变成0**, 我们的操作方式有2种:
1. 选择任意两项, 一项加1, 另一项减1；
2. 选择任意一项 加1 或者 减1，这里的选择一项也可以当作选择两项，将下标`n+1`位置当作处理的另一项。因为处理`n+1`项对原序列没有影响。

**这里使用差分数组，可以将对一段区间的处理变成每次取两位数的处理。** 我们需要求出如何使用最少次操作，使得差分数组元素全部为0。这里的原理是：**差分数组中负数和与正数和的绝对值的最大值**就是最小操作次数。原理自行模拟。

代码：
```c++
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
```


### 2.2 题目二：AcWing 797. 差分

> [AcWing 797. 差分](https://www.acwing.com/problem/content/799/)
> ![alt text](img/image-4.png)

代码：
```c++
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
```


### 2.3 题目三：AcWing 798. 差分矩阵

> [AcWing 798. 差分矩阵](https://www.acwing.com/problem/content/800/)
> ![alt text](img/image-5.png)
> ![alt text](img/image-6.png)


代码：
```c++
#include<iostream>
using namespace std;

const int N = 1010;
int e[N][N], b[N][N];
int n, m, k;

void add(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){  
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> e[i][j];
            add(i, j, i, j, e[i][j]);
        }
    
    while(k--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        add(x1, y1, x2, y2, c);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            e[i][j] = e[i - 1][j] + e[i][j - 1] - e[i - 1][j - 1] + b[i][j];
            cout << e[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
```


### 2.4 题目四：AcWing 5396. 棋盘

> [AcWing 5396. 棋盘](https://www.acwing.com/problem/content/5399/)
> ![alt text](img/image-7.png)

思路：典型的二维数组差分类的题目。

代码：
```c++
#include<iostream>
using namespace std;

const int N = 2010;
int e[N][N], b[N][N];
int n, m;

void add(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){  
    cin >> n >> m;
    while(m--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        add(x1, y1, x2, y2, 1);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            e[i][j] = e[i - 1][j] + e[i][j - 1] -e[i - 1][j - 1] + b[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(e[i][j] % 2 == 0)    cout << 0;
            else                    cout << 1;
        }
        cout << endl;
    }

    return 0;
}
```


### 2.5 题目五：AcWing 4655. 重新排序

> [AcWing 4655. 重新排序](https://www.acwing.com/problem/content/4658/)
>![alt text](img/image-8.png)

思路：这里的总体思路很神奇，但是确实想不到。总体来说，题目要求将数据重新排列之后可以将每次询问的区间之和求和之后，最大能够比原来的排列结果之和大多少。

这里题目意思理解了，就应该思考几个问题了：
1. 数据量是十万，每次求区间和如果是暴力，那么时间复杂度是`O(n^2)`，一定会超时，因此需要我们优化，这里显然可以使用差分优化。
2. 但是如何求取排列之后的区间和最大值？因为每个区间是有重合度的，**这里贪心的做法是我们将数值最大的元素放在询问次数最多的位置，以此类推，就能让新排列的区间和最大。**

3. 那么如何很快捷的求出这么多的区间和？这里又有一个技巧了。**计算出每个位置经历询问的次数，然后将次数和元素的乘积求和，即可得到全部询问的元素和。**
![alt text](img/image-9.png)
![alt text](img/image-10.png)

此时计算总和就是最大值。

综上：难点是能够想到利用询问次数来计算区间总和，同时理解贪心的原理。

代码：
```c++
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
typedef long long ll;
int e[N], b[N], cnt[N];
int n, m;

int main(){  
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> e[i];
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        b[l]++, b[r + 1]--;
    }

    for(int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + b[i];

    ll sumA = 0;
    for(int i = 1; i <= n; i++){
        sumA += (ll)e[i] * cnt[i];
    }

    sort(e, e + n + 1);
    sort(cnt, cnt + n + 1);
    
    ll sumB = 0;
    for(int i = 1; i <= n; i++){
        sumB += (ll)e[i] * cnt[i];
    }

    cout << sumB - sumA << endl;

    return 0;
}
```


