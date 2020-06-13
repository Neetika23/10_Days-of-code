//space -> O(n)
//time -> O(n*k)

#include <iostream>
#include<vector>
#define inf 1e9
using namespace std;
int solve(vector<int> h, int n, int k){
    vector<int> dp(n+1);
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = inf;
        for(int j = i-1 ; j >= 1 && (i-j) <= k ; j--){
            dp[i] = min(dp[i],abs(h[i]-h[j]) + dp[j]);
        }
    }
    return dp[n];
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    cout<<solve(h,n,k);
    return 0;
}
