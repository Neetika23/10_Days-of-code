class Solution {
public:
    int getSum(vector<int>& arr, int value){
        int sum = 0, n=arr.size();
        for(int i=0;i<n;i++){
            if(value < arr[i]){
                sum += value;
            }
            else{
                sum += arr[i];
            }
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size(), low, mid, high, max_ele = INT_MIN;
        for(int i=0;i<n;i++)
        {
            max_ele = max(max_ele, arr[i]);
        }
        low = 0;
        high = max_ele;
        while(low<high){
            mid = low + (high-low+1)/2;
            if(getSum(arr, mid) > target){
                high = mid-1;
            }
            else{
                low = mid;
            }
        }
        int tmp = getSum(arr,low);
        if(tmp == target || tmp > target)
            return low;
        
        int tmp1 = getSum(arr,low+1);
        return (abs(tmp1 - target) < abs(target - tmp) ? low+1 : low);
    }
};
