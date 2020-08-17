class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit, min_so_far = INT_MAX, curr_profit, res = INT_MIN, netProfit;
        
        if(n<2) return 0;
        
        //Preprocessing step
        vector<int> suffix(n,1);
        suffix[n-1] = prices[n-1];
        //Filling the suffix array
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1],prices[i]);
        }
        
        //Step 2: Assuming B2 as the ith day and get max profit (calc part 1)
        //Here used the concept of knowing the selling day but not the buying day like b4.
        //Setting up initial values
        min_so_far = min(prices[0], prices[1]);
        profit = max(0,prices[1]-prices[0]);
        
        res = profit;
        
        for(int i=2;i<n;i++){ //B2 cant be first and second value in array prices so started //with 2
            //Assuming you buy for the second time on this day (B2 happening here)
            
            if(i<n-1)
                curr_profit = max(0,suffix[i+1] - prices[i]); //This is profit from part 2
            else
                curr_profit = 0;
            netProfit = curr_profit + profit;
            
            res = max(res, netProfit);
            
            //Updating running profit
            profit = max(profit, prices[i] - min_so_far);
            min_so_far = min(min_so_far, prices[i]);
        }
        
        res = max(res,profit);
        
        return res;
    }
};
