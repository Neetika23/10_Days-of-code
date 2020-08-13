class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),j=n-1;  //Initialise j to lase ele
        
        for(int i=n-1;i>=0;i--){ //Iterate from right
            if(i+nums[i] >= j){ //condition of reachability
                j = i;  //updating j everytime for every iteration
            }
        }
        return j == 0; //return if nearest = 0, true if reached, false if not reached
    }
};
