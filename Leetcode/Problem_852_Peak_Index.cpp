// Time Complexity --> O(logn)
// Space Complexity --> O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //F*T*
        //P(x): A[x] > A[x+1]
        //First T
        int n = arr.size(), low, high, mid;
        low = 0;
        high = n-1;
        while(low < high){
            mid = low + (high-low)/2;
            if(arr[mid] > arr[mid + 1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        //Sanity check--> nosanity check needed since not needed in ques. Since the last element need
//not to be check here as its already present in the array. Its guraanteed that the last ele will be 
//that index we are looking for.
        return low;
    }
};
