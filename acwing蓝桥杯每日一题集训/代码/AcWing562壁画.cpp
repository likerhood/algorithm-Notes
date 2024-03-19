#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e6+10;
int t, n;
int e[N], sum[N];

int main(){
    cin >> t;
    int num = 0;
    while(t--){
        cin >> n;
        num++;
        string tmp;
        cin >> tmp;
        for(int i = 0; i <= n; i++){
            e[i + 1] = tmp[i] - '0'; 
        }

        int cnt = n % 2 == 1 ? n / 2 + 1 : n / 2;
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + e[i];
        }

        int res = -1;
        for(int i = 1, j = cnt; j <= n; j++, i++){
            int s = sum[j] - sum[i - 1];
            res = max(res, s);
        }
        cout << "Case #" << num << ": " << res << endl;
    }
    return 0;
}