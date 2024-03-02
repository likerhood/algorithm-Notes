#include<bits/stdc++.h>
using namespace std;

int bfs(string start){

    queue<string> que;
    unordered_map<string, int> mp;
    string end = "12345678x";

    if(start == end)    return 0;
    que.push(start);
    mp[start] = 0;

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    while(que.size()){
        string tmp = que.front();
        que.pop();
        int dist = mp[tmp];
        if(tmp == end)  return dist;
        // 一维坐标转换为二维坐标
        int t = tmp.find('x');
        int x = t / 3, y = t % 3;
        // 入队遍历
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx <3 && yy >= 0 && yy < 3){
                int k = xx * 3 + yy;
                swap(tmp[k], tmp[t]);
                // 如果没有访问过这个节点，入队
                if(mp.find(tmp) == mp.end()){
                    mp[tmp] = dist + 1;
                    que.push(tmp);
                }
                // 复原坐标
                swap(tmp[k], tmp[t]);
            }
        }

    }

    return -1;

}

int main(){

    string start = "", c;
    for(int i = 0; i < 9; i++){
        cin >> c;
        start += c;
    }

    cout << bfs(start);

    return 0;
}