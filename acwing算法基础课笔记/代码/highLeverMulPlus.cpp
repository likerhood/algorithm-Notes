# include<bits/stdc++.h>

using namespace std;
string a, b;
vector<int> A, B;

vector<int> Mul(vector<int> A, vector<int> B){
    vector<int> ans(A.size() + B.size(), 0);
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            ans[i + j] += A[i] * B[j];
        }
    }

    int pre = 0;
    for(int i = 0; i < ans.size(); i++){
        int tmp = ans[i] + pre;
        ans[i] = tmp % 10;
        pre = tmp / 10;
    }

    int i = ans.size() - 1;
    while(i >= 0 && ans[i] == 0){
        ans.pop_back();
        i--;
    }

    return ans;
}

int main(){
    
    cin >> a >> b;
    if(a == "0" || b == "0"){
        cout << 0;
        return 0;
    }
    for(int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    vector<int> ans = Mul(A, B);
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];

    return 0;
}