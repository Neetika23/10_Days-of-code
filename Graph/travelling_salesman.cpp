#include<bits/stdc++.h>
using namespace std;

#define INT_MAX 999999

int n = 4; //No. of cities
int dp[16][4];
//Adj Matrix defining the graph
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

//define one mask if all cities have been visited.
int visited_all = (1<<n) - 1;
int tsp(int mask, int pos){  //pos->index of current city.
    if(mask == visited_all){  //if visited_all = 1111 that has be initialized which meams all cities have been visited_all
        //is equal to the mask of curr city then we return the dist between cuurent city and first node,
        
        return dist[pos][0];
    }
    
    //Look up case.
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    //try to go to an unvisied city.
    for(int city=0;city<n;city++){
    //checking if the current city is visited or not.
    //eg. if we have mask  = 0110 and we have to check whether the second city is visited o not.
    //accoding to indexing 0,1,2,3, then we can do 1<<city(2nd) and create a temporary mask which will give us,
    //temporary mask = 0100 and do the anding and check if curr_city index is what. If its 1 means visited or 0 (non-visited).
        if((mask&(1<<city)) == 0){
            int newAns = dist[pos][city] + tsp(mask|(1<<city),city);  //by tsp func we are adding remaining answer.
            //mask|1<<city  -> mask = original mask and 1<<city means, if after A we are going to B which the left most node of
            //A then A(mask) = 0001 and B will have 0011. This mask value of B we get from 
            //1<<city.  The value of city for this case will be 1 since A is city 0..B is city 1 and so on.
            //1<<1 = 0010 and oring it with original  mask = 0001 we get 0011.
            ans = min(ans,newAns); //ans is final ans.
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    for(int i=0;i<(1<<n);i++){ //upto 2^n
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    cout<<tsp(1,0)<<endl; //tsp(1,0)  1->0001 mask and 0 is the initial node A.
    
    return 0;
}
//mask can take 2^n values starting from 0000 to 1111.
//and pos value will take n values.
//total ways = 2^n * n.
//2d dp table will be of order [2^n][n].
//complexity  = o(2^n * n).
