/* n--> n/3,n/2,n-1 */
#include<iostream>
#include<climits>
using namespace std;
int min_steps_topbottom(int n,int dp[]){ //Top down approch
//Base Case
    if(n==1){
        return 0;
    }
//Rec case
//look up if n is already computed
    if(dp[n] != 0){
        return dp[n];
    }
    //compute if dp[n] is not known
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    
    if(n%3 == 0){
        op1 = min_steps_topbottom(n/3,dp) + 1;
    }
    if(n%2 == 0){
        op2 = min_steps_topbottom(n/2,dp) + 1;
    }
    op3 = min_steps_topbottom(n-1,dp) + 1;
    int ans = min(min(op1,op2),op3);
    return dp[n] = ans;
}

//Bottom up Approach   computing dp[i] = O(1) and overall = O(n)
int min_steps_bottomup(int n){
    int dp[100] = {0};
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int op1,op2,op3;
        if(n%3 == 0){
            op1 = dp[i/3];
        }
    
        if(n%2 == 0){
            op2 = dp[i/2];
        }
        
        op3 = dp[i-1];
        
        dp[i] = min((op1,op2),op3) + 1;
    }
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    int dp[100] = {0};
    cout<<min_steps_topbottom(n,dp);
    cout<<min_steps_bottomup(n);
    return 0;
}
