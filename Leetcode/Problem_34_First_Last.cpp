class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), low, mid, high;
        vector<int> res;
        if(n==0){
            return {-1, -1};
        }
        low = 0;
        high = n-1;
        
        //Step 1 --> find the first position
        while(low < high){
            mid = low + (high - low)/2;
            if(nums[mid] >= target){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        if(nums[low] != target) return {-1, -1};
        res.push_back(low);
        
        //Step 2 --> find the last position
        low = 0;
        high = n-1;
        while(low<high){
            mid = low + (high - low + 1)/2;
            if(nums[mid]>target)
                high = mid-1;
            else
                low = mid;
        }
        res.push_back(low);
        return res;
    }
};
