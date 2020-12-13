/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getPeak(MountainArray &mountainArr){
        int low,mid,high,n=mountainArr.length();
        low=0,high=n-1;
        while(low<high){
            mid = low+(high-low)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    int binarySearch(MountainArray &mountainArr, int low, int high, int target, bool is_ascen){
        int mid;
        if(is_ascen){
            while(low<high){  //checking for last F in F*T*
                mid = low + (high-low+1)/2;
                if(mountainArr.get(mid) > target){
                    high = mid-1;
                }
                else{
                    low = mid;
                }
            }
            if(mountainArr.get(low) == target) return low;
            return -1;
        }
        else{
            while(low<high){   //checking for first F in T*F*
                mid = low+(high-low)/2;
                if(mountainArr.get(mid) > target){
                    low = mid + 1;
                }
                else{
                    high = mid;
                }
            }
            if(mountainArr.get(low) == target) return low;
            return -1;
        }
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        if(n==0){
            return -1;
        }
        int peak = getPeak(mountainArr);
        int left_side = binarySearch(mountainArr, 0, peak, target, true);
        if(left_side != -1) return left_side;
        int right_side = binarySearch(mountainArr, peak+1, n-1, target, false);
        return right_side;
    }
};
