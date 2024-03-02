#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int main(){
    int n, m;
    string s, p;
    cin >> n;
    cin >> p;
    cin >> m;
    cin >> s;
    // 求next数组
    int ne[N], j = -1;
    ne[0] = j;
    for(int i = 1; i < n; i++){
        while(j >= 0 && p[j + 1] != p[i]){
            j = ne[j];
        }
        if(p[i] == p[j + 1]){
            j++;
        }
        ne[i] = j;
    }

    // for(int i = 0; i < n; i++)
    //     cout << ne[i] << ' ';

    // 开始匹配
    for(int i = 0, j = -1; i < m; i++){
        while(j >= 0 && s[i] != p[j + 1]){
            j = ne[j];
        }

        if(s[i] == p[j + 1])    j++;

        if(j == n - 1){
            cout << i - j << ' ';
            j = ne[j];
        }
        
    }

    return 0;
}