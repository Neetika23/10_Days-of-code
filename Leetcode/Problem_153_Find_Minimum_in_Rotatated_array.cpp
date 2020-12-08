class Solution {
public:
    int findMin(vector<int>& nums) {
        //F*T*
        //first T
        //P(x):nums[i] < nums[0]
        int n = nums.size();
        if(nums[0] < nums[n-1]){
            return nums[0];
        }
        int low = 0, high = n-1, mid;
        while(low < high){
            mid = low + (high - low)/2;
            if(nums[mid] < nums[0]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        //Now we are left with one element
        //Sanity check
        return nums[low];
    }
};
