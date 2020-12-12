//Complexity: O(nlogw)  w is max element of array
class Solution {
public:
    int getSum(vector<int> &nums, int divisor){
        int tot = 0, i, n = nums.size();
        for(int i=0;i<n;i++){
            tot = tot+ceil((float)nums[i]/divisor);  //float is used so that we get the correct ceil.
        }
        return tot;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //Find the maximum using running maximum.
        
        int n = nums.size(), max_val=INT_MIN, low, high, mid;
        for(int i=0;i<n;i++){
            max_val = max(max_val, nums[i]);
        }
        //Now search space is 1 to max value
        //F*T*
        //p(x): sum <= threshold
        //first T
        low = 1, high = max_val;
        while(low<high){
            mid = low + (high-low)/2;
            if(getSum(nums,mid) <= threshold){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        return low;
    }
};
