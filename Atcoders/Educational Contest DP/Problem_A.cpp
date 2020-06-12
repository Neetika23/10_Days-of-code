#include <iostream>
#include<vector>
#define inf 1e9
using namespace std;

int solve(vector<int> h, int n){
    vector<int> dp(n+1);
    dp[1] = 0; // 0 cose is incurred from reaching s1 to s1
    for(int i=2;i<=n;i++){
        int op1,op2;
        op1 = abs(h[i] - h[i-1]) + dp[i-1];
        op2 = (i==2) ? inf : abs(h[i] - h[i-2]) + dp[i-2];
        dp[i] = min(op1,op2);
    }
return dp[n];
}
int main() {
    int n;
    cin>>n;
    vector<int> h(n+1); //h(n+1) denotes that vector is havinf 1 based indexing.
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    cout<<solve(h,n);
}
