#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<PII > segs, res;

void merge(){
    int st = INT_MIN, ed = INT_MIN;
    for(int i = 0; i < segs.size(); i++){
        // 上一个区间的右端点小于下一个区间的左端点
        if(ed < segs[i].first){
            if(st != INT_MIN)
                res.push_back({st, ed});
            // 更新维护区间的左右端点
            st = segs[i].first;
            ed = segs[i].second;
        }else{
            // 更新左端点
            ed = max(ed, segs[i].second);
        }
    }

    // 注意加入最后一个区间
    res.push_back({st, ed});
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    sort(segs.begin(), segs.end());

    merge();
    cout << res.size();
    return 0;
}