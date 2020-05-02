#include<iostream>
using namespace std;
int find_zeroes(int n){
	int count = 0;
	int p = 5;
	while((n/p)>0){
		count += (n/p);
		p = p*5;
	}
	return count;
}


int main () {
	long long int n;
	cin>>n;
	cout<<find_zeroes(n);
	return 0;
}