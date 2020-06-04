//Recursive
#include<bits/stdc++.h>
using namespace std;
int profit(int wines[],int i,int j,int y){
    //Base case
    if(i>j){
        return 0;
    }
    //Rec case
    int op1 = wines[i] * y + profit(wines,i+1,j,y+1);
    int op2 = wines[j] * y + profit(wines,i,j-1,y+1);
    
    return max(op1,op2);
}
int main(){
    int wines[]={2,3,5,1,4}; //Greedy --> 49  dp-->50
    int n = sizeof(wines) / sizeof(int);
    int y=1;
    cout<<profit(wines,0,n-1,y);
    
    return 0;
}

//Top down
#include<bits/stdc++.h>
using namespace std;

int profit(int wines[],int i,int j,int y, int dp[][100]){
    //Base case
    if(i>j){
        return 0;
    }
    //look up
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    
    //Rec case
    int op1 = wines[i] * y + profit(wines,i+1,j,y+1,dp);
    int op2 = wines[j] * y + profit(wines,i,j-1,y+1,dp);
    
    return dp[i][j] = max(op1,op2);
}
int main(){
    int wines[]={2,3,5,1,4}; //Greedy --> 49  dp-->50
    int dp[100][100] = {0};
    int n = sizeof(wines) / sizeof(int);
    int y=1;
    cout<<profit(wines,0,n-1,y,dp);
    
    return 0;
}

//bottom up is tricky since we need to fill the diagonals first.
