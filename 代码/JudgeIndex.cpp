#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < m; i++)  cin >> b[i];

    int i, j;
    for(i = 0, j = 0; i < n; i++, j++){
        while(j < m && a[i] != b[j]){
            j++;
        }
        if(j == m){
            cout << "No" <<endl;
            break;
        }
    }
    if(i == n)  cout << "Yes" << endl;

    return 0;
}