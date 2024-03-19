#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

const int N = 100005;
int n, q;
int e[N];


int main(){

    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> e[i];

    while(q--){
        int k;
        cin >> k;

        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(e[mid] >= k) r = mid;
            else            l = mid + 1;
        }
        if(e[l] != k){
            cout << -1 << ' ' << -1 << endl;
            continue;
        }  

        int res = l;
        l = 0, r = n - 1;   
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(e[mid] <= k) l = mid;
            else            r = mid - 1;
        }

        cout << res << ' ' << l << endl;

    }


    return 0;
}
