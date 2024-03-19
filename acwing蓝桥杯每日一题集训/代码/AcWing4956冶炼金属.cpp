#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10004;
int n;
int A[N], B[N];

// 求最小的答案
bool check1(int x){
    for(int i = 0; i < n; i++){
        int t = A[i] / x;
        if(t > B[i])    return false;    
    }
    return true;
}

// 求最大的答案
bool check2(int x){
    for(int i = 0; i < n; i++){
        int t = A[i] / x;
        if(t < B[i])    return false;
    }
    return true;
}


int main(){

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i] >> B[i];
    
    int l = 1, r = 1e9;
    int res1 = 0, res2 = 0;
    while(l < r){
        int mid = l + r >> 1;
        if(check1(mid))
            r = mid;
        else l = mid + 1;
    }

    res1 = l;

    l = 1, r = 1e9;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check2(mid))
            l = mid;
        else    r = mid - 1;
    }
    res2 = l;

    cout << res1 << " " << res2;
    return 0;
}