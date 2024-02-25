#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int nums[N];
char op[N];
int opTop, numsTop;     // 建立两个栈，分别存放操作数和运算符
string s;               // 表达式
unordered_map<char, int> mp = {     //运算符优先级
    {'(', 0},
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {')', 3}
};

void init(){            // 栈初始化
    opTop = -1, numsTop = -1;
}

bool isNum(char c){     // 判断是否是数字
    int x = c - '0';
    return x >= 0 && x <= 9;
}

int toNum(int i, int j){    // 将字符串转化为数字
    int tmp = 0;
    while(i <= j){
        tmp = tmp * 10 + s[i] - '0';
        i++;
    }
    return tmp;
}

void compute(){             // 计算一个运算符对应的表达式的结果
    char c = op[opTop];
    opTop--;
    int b = nums[numsTop];
    numsTop--;
    int a = nums[numsTop];
    numsTop--;

    int res = 0;
    if(c == '+')    res = a + b;
    else if(c == '-')   res = a - b;
    else if(c == '*')   res = a * b;
    else if(c == '/')   res = a / b;
    nums[++numsTop] = res;
}

int main(){

    init();     //初始化
    cin >> s;   //输入表达式
    
    for(int i = 0; i < s.size(); i++){
        if(isNum(s[i])){        // 将连续的数字压入栈
            int j = i;
            while(isNum(s[j]) && j < s.size())  j++;
            int tmp = toNum(i, j - 1);
            i = j - 1;          // 这里i要少一位，因为末尾i++
            nums[++numsTop] = tmp;
        }else if(s[i] == '('){  // '('直接压入栈，等待遇到了')'返回
            op[++opTop] = '(';
        }else if(s[i] == ')'){  // 遇到')'，将()内部的式子都计算了
            while(op[opTop] != '('){
                compute();      // 计算()内部的式子
            }
            opTop--;            // 将最后的'('弹出
        }else{                  //对于运算符的情况
            while(mp[s[i]] <= mp[op[opTop]]){
                compute();
            }
            op[++opTop] = s[i];
        }
    }

    // 将栈里面的最后结果计算出来
    while(opTop != -1){
        compute();
    }

    int ans = nums[numsTop];
    cout << ans << endl;
    
    return 0;
}