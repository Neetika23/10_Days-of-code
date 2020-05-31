/*There are five approaches: 1. Recursion  2.Top Bottom  3. Bottom Up  4.Bottom up with space optimization  
5.Matrix Exponentiation (Reduce Space complexity to O(logn) */
#include<iostream>
using namespace std;

/*Bottom Up Approach (Space Complexity = O(n) and Time Complexity = O(n))*/
int fib_bottomup(int n){
	int dp[100]={0};
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

/*Top Bottom Approach (Space Complexity = O(n) and Time Complexity = O(n))) */
int fib(int n, int dp[]){
  if(n==0 || n==1){
    return n;
  }
  if(dp[n]!=0)
    return dp[n];
  int ans;
  ans = fib(n-1,dp),fib(n-2,dp);
  return ans = dp[n];
  }
  
  /*Bottom Up with space optimization (Space Complexity = O(1) and Time Complexity = O(n)) */
  int fib(int n){
    if(n==0 || n==1){
      return n;
    }
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++){
      c=a+b;
      a=b;
      b=c;
    }
    return c;
    }
    
int main() {
	int n;
	cin>>n;
	cout<<fib_bottomup(n);
	return 0;
}
