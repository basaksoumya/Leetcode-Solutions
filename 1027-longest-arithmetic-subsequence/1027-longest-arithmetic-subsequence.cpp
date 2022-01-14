class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(); int ret = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(2001, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int diff = nums[j] - nums[i]+1000;
                dp[j][diff] = max(2, dp[i][diff]+1);
                ret = max(ret, dp[j][diff]);
            }
        }
        return ret;
    }
};