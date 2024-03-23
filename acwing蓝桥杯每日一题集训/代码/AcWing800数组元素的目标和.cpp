#include<iostream>

using namespace std;

const int N = 100005;
int n, m, x;
int a[N], b[N];

int main(){

    cin >> n >> m >> x;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < m; i++)  cin >> b[i];

    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        int tmp = a[i] + b[j];
        if(tmp == x)    break;
        else if(tmp > x)    j--;
        else                i++;
    }

    cout << i << " " << j << endl;
    
    return 0;
}