#include<bits/stdc++.h>
using namespace std;

const int N = 100020;
int son[N][26], cnt[N];
int idx;

void insert(string s){
    int p = 0;          // 表示从头节点开始
    for(int i = 0; i < s.size(); i++){
        int u = s[i] - 'a';             // 字符映射为数字
        if(son[p][u] == 0)  son[p][u] = ++idx;      // 如果没有节点，就创建节点
        p = son[p][u];          //指向该节点的下一个位置，idx表示当前是第几个节点
    }
    //访问到最后一个字符之后，标记是第几次插入
    //因为idx是节点编号，每一个单词的最后一个字符都对应着一个编号
    //编号最多也是只有所有字符串加起来的长度而已。
    cnt[p]++;
}

int query(string s){
    int p = 0;
    for(int i = 0; i < s.size(); i++){
        int u = s[i] - 'a';
        if(son[p][u] == 0)  return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    cin >> n;
    while(n--){
        char op;
        string s;
        cin >> op >> s;
        if(op == 'I')   insert(s);
        else if(op == 'Q'){
            int num = query(s);
            cout << num << endl;
        }
    }

    return 0;
}