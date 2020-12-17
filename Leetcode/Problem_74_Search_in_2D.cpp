class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //F*T*
        //A(x) > target OR a(x) >=target 
        //find last F or first T resp.
        if(matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size(), i, j;
        if(n==0) return false;
        int low = 0, high = m*n-1, mid;
        while(low < high){
            mid = low + (high-low)/2;
            i = mid/n; //row
            j = mid%n; //column
            
            if(matrix[i][j] >= target)
                high = mid;
            else
                low = mid+1;
        }
        //Sanity check
        i = low/n, j = low%n;
        if(matrix[i][j] ==  target)
            return true;
        else
            return false;
        
    }
};
