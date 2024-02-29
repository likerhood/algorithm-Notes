#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
vector<int> e[N], s;
int d[N];               //记录入度

bool topSort(){
    
    queue<int> que;
    for(int i = 1; i <= n; i++)
        if(d[i] == 0)   que.push(i);

    while(que.size()){
        int tmp = que.front();
        s.push_back(tmp);
        que.pop();
        for(auto t : e[tmp]){
            d[t]--;
            if(d[t] == 0){
                que.push(t);
            }
        }
    }

    // for(auto x : s)
    //     cout << x << ' ';

    if(s.size() == n){
        return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        d[y]++;
    }

    if(topSort()){
        for(auto x : s)
            cout << x << ' ';
    }else{
        cout << -1;
    }
    return 0;
}