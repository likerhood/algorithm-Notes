#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int e[N], ans[N], n;
stack<int> st;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> e[i];
    }

    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= e[i]){
            st.pop();
        }

        if(st.empty())  ans[i] = -1;
        else            ans[i] = st.top();

        st.push(e[i]);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}