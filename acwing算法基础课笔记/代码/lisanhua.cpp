#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 300010;
int n, m;
int sum[N]; //sum表示i对应的x坐标的前缀和
int a[N];   // a[i]表示i下标对应的x坐标对应的值
vector<int> alls;   // 存放排序好的x坐标
vector<PII > add, query;    // 存放对应x插入的数值和查询的区间范围

int main(){

    // 先输入数据
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, c;
        cin >> x >> c;
        alls.push_back(x);
        add.push_back({x, c});
    }

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 在alls数组中进行排列和去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // unique函数的原理：使得只出现一次的数在一个区域，
    //剩余的有重复的接在第一个end(最后未重复出现的位置的下标)的后面，
    //再把其与第二个end之间(数组末尾)的值erase

    // 获得x数值和数组下标的映射
    unordered_map<int, int> mp;
    for(int i = 0; i < alls.size(); i++){
        mp[alls[i]] = i + 1;
    }

    // 开始对x坐标进行插值处理
    for(int i = 0; i < add.size(); i++){
        int index = mp[add[i].first];
        a[index] += add[i].second;
    }

    // 计算前缀和
    for(int i = 1; i <= alls.size(); i++){
        sum[i] = sum[i - 1] + a[i];
    }

    // 给出每段查询区间的值
    for(int i = 0; i < m; i++){
        int l = mp[query[i].first];
        int r = mp[query[i].second];
        int s = sum[r] - sum[l - 1];

        cout << s << endl;
    }

    return 0;
}