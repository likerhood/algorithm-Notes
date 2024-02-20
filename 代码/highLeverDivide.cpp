#include<bits/stdc++.h>

using namespace std;
int tmp;

vector<int> Divide(vector<int> A, int b){
    vector<int> ans(A.size(), 0);
    for(int i = A.size() - 1; i >= 0; i--){
        tmp = tmp * 10 + A[i];
        int res = tmp / b;
        ans[i] = res;
        tmp %= b;
    }

    int i = ans.size() - 1;
    while(i >= 0 && ans[i--] == 0){
        ans.pop_back();
    }
    return ans;
}

int main(){
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }

    vector<int> ans = Divide(A, b);
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i];
    }
    if(ans.size() == 0)
        cout << 0;
    cout << endl;
    cout << tmp;

    return 0;
}