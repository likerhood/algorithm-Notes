#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 105;
int a[N], b[N], spend[N];
int n, t;


int main(){

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 2; i <= n; i++){
        int tmp = 0;
        cin >> tmp;
        spend[i] = spend[i - 1] + tmp;
    }

    cin >> t;

    int res = 0;
    for(int i = 1; i <= n; i++){
        int fishtime = t - spend[i];
        int fish = 0;
        priority_queue<PII> que;

        // 将i个池塘全部压入队列
        for(int j = 1; j <= i; j++)
            que.push({a[j], j});

        while(que.size() && fishtime > 0){
            PII tmp = que.top();
            int y = tmp.second;
            int x = tmp.first;
            fish += x;
            fishtime--;
            que.pop();

            x -= b[y];
            if(x > 0)   que.push({x, y});
        }

        res = max(res, fish);
    }

    cout << res << endl;
    return 0;
}