class Solution {
public:
    int total = 0;
    int solve(vector<int> &nums,int i,int sum,int target,vector<vector<int>> &dp) {
        
        if(i == nums.size()) {
            if(target == sum) 
               return 1;
            else
                return 0;
        }
        else {
        
            if(dp[i][total+sum] != INT_MIN)
                return dp[i][total+sum];
        
            int a = solve(nums,i+1,sum-nums[i],target,dp);
            int b = solve(nums,i+1,sum+nums[i],target,dp);
        
            dp[i][total+sum] = a + b;
            
            return a+b;
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(),sum = 0;
        for(auto it : nums)
            total += it;
        vector<vector<int>> dp(n,vector<int>(2*(total+1)+1,INT_MIN));
        int ans = solve(nums,0,0,target,dp);
        return ans;
    }
};