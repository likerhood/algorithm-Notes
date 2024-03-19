#include<iostream>
#include<algorithm>
using namespace std;
/*
输入的第一行包含两个整数 n,len用一个空格分隔，分别表示会打开的阀门数和管道长度。
接下来 n行每行包含两个整数 Li,Si用一个空格分隔，表示位于第 Li段管道中央的阀门会在 Si时刻打开。
对于所有评测用例，1≤n≤105，1≤Si，len≤109，1≤Li≤len，Li−1<Li
*/

typedef pair<int, int> PII;
typedef long long LL;
const int N = 100005;
int n, len;
PII w[N], q[N];

bool check(int mid){

    // 遍历全部的开水阀口，全部满足条件的开水阀口的线段区间记录下来
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(w[i].second <= mid){
            int t = mid - w[i].second;
            int x = max((LL) 1, (LL) w[i].first - t);
            int y = min((LL) len, (LL) w[i].first + t);
            q[idx++] = {x, y};
        }
    }

    // 开始合并区间
    sort(q, q + idx);
    int sd = -10, ed = -10;
    for(int i = 0; i < idx; i++){
        if(q[i].first <= ed || q[i].first == ed + 1){
            if(sd == -10)   sd = q[i].first;
            ed = max(q[i].second, ed);
        }else{
            sd = q[i].first, ed = max(q[i].second, ed);
        }
    }

    if(sd == 1 && ed == len)    return true;
    else                        return false;


}

int main(){
    cin >> n >> len;
    for(int i = 0; i < n; i++)  cin >> w[i].first >> w[i].second;

    // 二分
    int l = 1, r = 2e9;
    while(l < r){
        int mid = (LL) l + r >> 1;
        if(check(mid))  r = mid;
        else            l = mid + 1;
    }

    cout << l << endl;

    return 0;
}