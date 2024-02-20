#include<bits/stdc++.h>
using namespace std;

string a, b;
int main(){
    cin >> a >> b;
    int pre = 1;
    if(a.size() < b.size()){
        pre *= -1;
        swap(a, b);
    }
    else if(a.size() == b.size()){
        int i = 0;
        for(i = 0; i < a.size() && a[i] == b[i]; i++);
        if(i == a.size()){
            pre = 0;
        }else if(a[i] < b[i]){
            pre *= -1;
            swap(a, b);
        }
    }

    if(pre == 0){
        cout << 0 << endl;
        return 0;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int cnt = 0, i = 0;
    for(i = 0; i < b.size(); i++){
       int x = a[i] - '0' + cnt;
       int y = b[i] - '0';
       if(x < y){
            cnt = -1;
            x += 10;
       }else{
            cnt = 0;
       }
       a[i] = x - y + '0';
    }

    while(cnt && i < a.size()){
        int x = a[i] - '0' + cnt;
        if(x < 0){
            a[i] = x + 10 + '0';
            cnt = -1;
        }else{
            a[i] = x + '0';
            cnt = 0;
        }
        i++;
    }

    for(int i = a.size() - 1; i >= 0; i--){
        if(a[i] != '0')
            break;
        else
            a.pop_back();
    }

    reverse(a.begin(), a.end());
    if(pre == -1)
        cout<< '-';
    cout << a << endl;

    return 0;
}


