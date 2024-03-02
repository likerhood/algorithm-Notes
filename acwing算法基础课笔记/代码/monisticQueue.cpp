#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, k;
int a[N];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)  cin >> a[i];

    deque<int> que;     // 单调队列

    // 求滑动窗口最小值，单调队列的数值是非严格单调递增的
    for(int i = 0; i < n; i++){
        // 确保队列中队头的元素已经不是之前滑动窗口中队头的元素
        if(i - k >= 0 && !que.empty() && a[i - k] == que.front()){
            que.pop_front();
        }
        // 维护单调队列
        // 这里的弹出条件必须不带等号
        while(!que.empty() && que.back() > a[i]){
            que.pop_back();
        }
        // 加入队列
        que.push_back(a[i]);
        if(i - k + 1 >= 0){     //滑动窗口已满
            cout << que.front() << ' ';
        }
    }
    cout << endl;

    // 求滑动窗口的最大值
    que.clear();
    for(int i = 0; i < n; i++){
        // 判断队首元素
        if(i - k >= 0 && !que.empty() && que.front() == a[i - k]){
            que.pop_front();
        }

        // 维护队列
        while(!que.empty() && que.back() < a[i]){
            que.pop_back();
        }

        //将当前元素加入队尾
        que.push_back(a[i]);

        // 输出答案
        if(i - k + 1 >= 0){
            cout << que.front() << ' ';
        }
    }

    return 0;
}