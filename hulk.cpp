#include<iostream>
using namespace std;
int save_earth(int n){
	int res = 0;
	while(n>0){
		res += n & 1;
		n = n >> 1;
	}
	return res;
}
int main() {
	int test,n;
	cin>>test;
	for(int i=0;i<test;i++){
		cin>>n;
		cout<<save_earth(n)<<endl;
	}
	return 0;
}
