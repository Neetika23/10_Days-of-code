// Brute Force
// O(n^2) time complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxR, profit, result = INT_MIN;
        for(int i=0;i<n-1;i++){ //lopp goes till n-1, because buying on last day does not matter
            //Assuming buying day to be ith
            //Find max on its right
            maxR = INT_MIN;
            for(int j=i+1;j<n;j++){
                maxR = max(maxR, prices[j]);
            }
            
            //Computing profit
            profit = maxR - prices[i];
            result = max(result, profit);
        }
        return max(0, result); //If in some case the result comes out to be negative,
                                //it will return 0 and not the negative value, i.e no-profit
    }
};

//Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max_so_far = INT_MIN, profit, result = INT_MIN;
        
        if(n==0) return 0;
        
        max_so_far = prices[n-1]; //let last ele be max initially.
        for(int i = n-2 ; i >= 0 ; i--){ //starting from second last ele
            //Assume that you buy on the ith day
            profit = max_so_far - prices[i];
            result = max(result,profit); //to keep track of final maximum result.
            
            max_so_far = max(max_so_far, prices[i]);
        }
        return max(0,result);
    }
};
