class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for(int len = 2; len <= n; ++len){
            for(int i = 0; i < len; ++i){
                dp[len] += dp[i] * dp[len - 1 - i];
            }
        }
        return dp[n];
    }
};