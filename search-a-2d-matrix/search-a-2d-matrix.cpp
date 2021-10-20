class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int lo = 0 , hi = row * col - 1, mid;
        
        while(lo <= hi) {
            mid = lo + (hi-lo) / 2;
            if(matrix[mid/col][mid%col] == target)
                return true;
            else if(matrix[mid/col][mid%col] > target) {
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return false;
    }
};