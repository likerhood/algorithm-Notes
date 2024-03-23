#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;
typedef pair<int, int> PII;
int n, d, k;
PII q[N];
int cnt[N];
bool s[N];

int main(){

    cin >> n >> d >> k;
    for(int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    
    sort(q, q + n);

    // 双指针
    for(int i = 0, j = 0; i < n; i++){
        cnt[q[i].second]++;
        while(q[i].first - q[j].first >= d){
            cnt[q[j].second]--;
            j++;
        }

        if(cnt[q[i].second] >= k)   s[q[i].second] = true;

    }

    for(int i = 0; i < 1e5 + 1; i++)
        if(s[i])    cout << i << endl;

    return 0;
}