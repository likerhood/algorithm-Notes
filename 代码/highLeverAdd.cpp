#include<bits/stdc++.h>
using namespace std;

string a, b;

int main(){
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if(a.size() < b.size())
        swap(a, b);
    
    int cnt = 0, i = 0;
    for(i = 0; i < b.size(); i++){
        int tmp = a[i] - '0' + b[i] - '0' + cnt;
        cnt = tmp / 10;
        a[i] = tmp % 10 + '0';
    }

    while(cnt && i < a.size()){
        int tmp = a[i] - '0' + cnt;
        cnt = tmp / 10;
        a[i++] = tmp % 10 + '0';
    }

    if(cnt && i == a.size()){
        a.push_back(cnt + '0');
    }

    reverse(a.begin(), a.end());
    cout << a << endl;

    return 0;
}