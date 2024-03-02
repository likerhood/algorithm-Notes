#include<bits/stdc++.h>
using namespace std;

int n, use[10];
vector<int> path;
void dfs(int t){
    if(t == n){
        for(int i = 0; i < path.size(); i++)
            cout << path[i] << ' ';
        cout << endl;
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(use[i] == 0){
            use[i] = 1;
            path.push_back(i);
            dfs(t + 1);
            use[i] = 0;
            path.pop_back();
        }
    }
}

int main(){
    cin >> n;
    dfs(0);
    return 0;
}