#include<bits/stdc++.h>
using namespace std;
int n, k;
const int N = 100005;
int a[N];

int binarySearch_first(int t){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] >= t) r = mid;
        else            l = mid + 1;
    }

    if(a[l] == t)
        return l;
    else 
        return -1;
}

int binarySearch_last(int t){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(a[mid] <= t) l = mid;
        else            r = mid - 1;
    }
    if(a[r] == t)
        return r;
    else    
        return -1;
}


int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    while(k--){
        int t;
        cin >> t;
        int t_first = binarySearch_first(t);
        if(t == -1){
            cout << -1 << ' ' << -1 << endl;
        }else{
            int t_last = binarySearch_last(t);
            cout<< t_first << ' ' << t_last << endl;
        }
    }
    return 0;
}