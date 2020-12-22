//simplest approach is to binary search on each row. It complexity will be O(m*log(n)).

//Complexity O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), i, j;
        i = 0, j = n-1;
        while(i < m && j >= 0){
            //Decision
            if(matrix[i][j] == target) return true;
            
            else if(matrix[i][j] < target)
                i++;
            else if(matrix[i][j] > target)
                j--;
        }
        return false;
    }
};
