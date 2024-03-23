#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100005;
int n, L;
int s[N];

// 判断函数
bool check(int h){
    int cnt = 0, res = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] >= h)   res++;
        else if(s[i] + 1 == h ) cnt++;
    }

    cnt = min(cnt, L);
    res += cnt;
    return res >= h;
}


int main(){

    cin >> n >> L;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    
    int l = 0, r = n;
    while(l < r){
        int mid = l + r + 1>> 1;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }
   
    cout << l;

    return 0;
}