class Solution {
public:
    int tripsCount(vector<int> &weights, int capacity){
        int trips = 0, i = 0, n=weights.size(), currSum=0;
        
        //1,3,5  and c=4
        while(i<n){
            if(currSum + weights[i] > capacity){
                trips++;
                currSum = 0;
            }
            else{
                currSum = currSum + weights[i];
                i++;
            }
        }
        
        return (++trips);
    }
    int shipWithinDays(vector<int>& weights, int D) {
        //Find out search space
        //low = max(array)
        //high = sum(array)
        int n = weights.size(), i, maxi = INT_MIN, sum = 0;
        int low, high, mid;
        for(i=0;i<n;i++){
            maxi = max(maxi, weights[i]);
            sum = sum + weights[i];
        }
        //FFFFTTTT
        //P(x) = trip <= D
        //First T
        low = maxi, high = sum;
        while(low<high){
            mid = low + (high-low)/2;
                if(tripsCount(weights, mid) <= D){
                    high = mid;
                }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
