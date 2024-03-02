#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(){
	string s="222.22";
	cout<<"s="<<s<<endl;
	int a = 222;
	int ot = stoi(s,0,10);
	int ol = stol(s,0,10);
	float of = stof(s,0);
	double od = stod(s,0); 
	cout<<"ot="<<ot<<endl;
	cout<<"ol="<<ol<<endl;
	cout<<"of="<<of<<endl;
	cout<<"od="<<od<<endl;
	return 0;
}