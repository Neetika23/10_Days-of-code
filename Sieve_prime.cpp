#include<iostream>
using namespace std;
void prime_sieve(int *p, int n){
	//first mark all odd numbers as prime
	for(int i=3;i<=n;i+=2){
		p[i]=1;
	}

	//sieve
	for(int i=3;i<=n;i+=2){
		//if the current number is not marked, it is prime
		if(p[i] == 1){
			//mark all multiple of i as not prime
			for(int j=i*i;j<=n;j=j+i){
				p[j] = 0;
			}
		}
	}
	//special cases
	p[2] = 1;
	p[0] = p[1] = 0;

}
int main() {
	int n;
	cin>>n;
	int p[100005] = {0}; //0, 1 array. 1 will be at the places where number is prime.
	prime_sieve(p,n);
	for(int i=0;i<=n;i++){
		if(p[i]==1)
			cout<<i<<" ";
	}
	return 0;
}
