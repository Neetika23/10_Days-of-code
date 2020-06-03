#include<bits/stdc++.h>
using namespace std;

//Top down approach
int min_coin(int n, int coins[], int T, int dp[]){
    
    if(n==0){
        return 0;
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ans = INT_MAX;
    for(int i=0;i<T;i++){
        if(n-coins[i] >= 0){
            int sub = min_coin(n-coins[i], coins, T, dp);
            ans = min(ans,sub + 1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

//Bottom Up approach
int min_coin1(int N, int coins[], int T){
    int dp[100] = {0};
    
    
    for(int n=1;n<=N;n++){
        //initilise current ans as int_max
        dp[n] = INT_MAX;
        for(int i=0;i<T;i++){
            if(n - coins[i] >= 0){
                int sub_prob = dp[n-coins[i]];
                dp[n] = min(dp[n], sub_prob+1);
            }
        }
    }
    return dp[N];
    
    
}

int main(){
    int n = 15;
    int coins[] = {1,7,10};
    int dp[100] = {0};
    int T = sizeof(coins)/sizeof(int);
    //cout<<min_coin(n,coins,T,dp);
    cout<<min_coin1(n,coins,T);
    return 0;
}
