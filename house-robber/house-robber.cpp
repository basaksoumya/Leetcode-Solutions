class Solution {
public:
    
    int solve(vector<int> &nums,int i, int amount,vector<vector<int>> &dp) {
        
        if(i >= nums.size()) {
            return amount;
        }
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int a = solve(nums,i+2,amount+nums[i],dp);
        int b = solve(nums,i+1,amount,dp);
        
        return dp[i][amount] = max(a,b);
    }
    
    
    
    
    int rob(vector<int>& nums) {
        int n = nums.size() , amount = 0, total = 0;
        for(auto it : nums)
            total += it;
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        int ans = solve(nums,0,amount,dp);
        
        return ans;
    }
};