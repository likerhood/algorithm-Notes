#include<iostream>

using namespace std;

const int N = 100003;
int q[N], cnt[N];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> q[i];

    int res = 0;
    for(int i = 0, j = 0; j < n; j++){
        cnt[q[j]]++;
        while(cnt[q[j]] > 1 && i < j){
            cnt[q[i]]--;
            i++;
        }
        res = max(res, j - i + 1);
    }

    cout << res << endl;
    return 0;
}