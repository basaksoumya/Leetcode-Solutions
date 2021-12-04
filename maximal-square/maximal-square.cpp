class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(),ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i = n -1 ; i >= 0 ; i--) {
            for(int j = m-1 ; j >= 0 ; j--) {
                if(i == n-1 || j == m-1) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    if(matrix[i][j] == '0') {
                        dp[i][j] = 0;
                    }
                    else {
                        
                        int mini = min(dp[i+1][j],dp[i][j+1]);
                        mini = min(mini,dp[i+1][j+1]);
                    
                        dp[i][j] = mini + 1;
                    }
                }
                
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans*ans;
    }
};