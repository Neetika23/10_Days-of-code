//dont calculate prime for every query. Just precompute the prime array once
//and use that in every query.
//also find cummulative sum of no. of primes upto that number and for any range,
//for eg. 11 to 20 calculate no. prime prime as: cummu(20) - cummu(10).

#include<iostream>
#define ll long long
using namespace std;
void prime_sieve(int *p){
	//first mark all odd numbers as prime
	for(int i=3;i<=1000000;i+=2){
		p[i]=1;
	}

	//sieve
	for(ll i=3;i<=1000000;i+=2){
		//if the current number is not marked, it is prime
		if(p[i] == 1){
			//mark all multiple of i as not prime
			for(ll j=i*i;j<=1000000;j=j+i){
				p[j] = 0;
			}
		}
	}
	//special cases
	p[2] = 1;
	p[0] = p[1] = 0;

}
int main() {
	int p[1000005] = {0}; //0, 1 array. 1 will be at the places where number is prime.
	prime_sieve(p);
	
	int csum[1000005] = {0};

	//precompute primes upto index i
	for(int i=1;i<=1000000;i++){
		csum[i] = csum[i-1] + p[i];
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<csum[b] - csum[a-1]<<endl;
	}
	return 0;
}
