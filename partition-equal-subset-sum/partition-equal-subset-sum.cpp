class Solution {
public:
    
    int canPartitionUtill(vector<int> &nums,int i,int target,vector<vector<int>> &dp) {
        
        if(target < 0)
            return 0;
        if(i == nums.size()) {
            if(target == 0) {
                return 1;
            }else {
                return 0;
            }
        } 
        
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        
        int ans1 = canPartitionUtill(nums,i+1,target-nums[i],dp);
        int ans2 = canPartitionUtill(nums,i+1,target,dp);
        
        dp[i][target] = (ans1 + ans2) == 2 ? 1 : ans1+ans2;
        
        return dp[i][target];
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        for(int i = 0 ; i < n ; i++) 
            sum += nums[i];
        
        if(sum%2)
            return false;
        sum /= 2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        canPartitionUtill(nums,0,sum,dp);
        if(dp[0][sum])
            return true;
        else
            return false;
    }
};