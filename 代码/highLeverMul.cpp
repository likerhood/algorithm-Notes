#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    if(b == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }

    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < A.size(); i++){
        int tmp = A[i] * b + cnt;
        ans.push_back(tmp % 10);
        cnt = tmp / 10;
    }

    while(cnt){
        ans.push_back(cnt % 10);
        cnt /= 10;
    }

    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i];
    }
    
    return 0;
}