class Solution {
public:
    int count(vector<vector<int>> &matrix,int target) {
        
        int n = matrix.size(),ans = 0;
        
        for(int r = 0 ; r < n ; r++) {
            int lo = 0 , hi = n-1,mid;
            while(lo <= hi) {
                
                mid = lo + (hi - lo) / 2;
                if(matrix[r][mid] <= target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
                    
            }
            ans += lo;
        }
        
        return ans;
    }
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int lo = matrix[0][0], hi = matrix[n-1][n-1],mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int val = count(matrix,mid);
            if(val >= k)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};