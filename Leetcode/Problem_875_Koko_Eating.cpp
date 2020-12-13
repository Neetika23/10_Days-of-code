class Solution {
public:
    int getK(vector<int> &piles, int k){
        int sum = 0, n=piles.size();
        for(int i=0;i<n;i++){
            sum += ceil((float)piles[i]/k);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size(), low, mid, high, max_val = INT_MIN;
        for(int i=0;i<n;i++){
            max_val = max(max_val, piles[i]);
        }
        low = 1;
        high = max_val;
        while(low < high){
            mid = low+(high-low)/2;
            if(getK(piles,mid) <= H){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(getK(piles,low)) return low;
        return -1;
    }
};
