class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return 0;
        if(n == 1) 
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        if(n == 3)
            return max(nums[0],max(nums[1],nums[2]));
        
        int dp[n], ans1 = INT_MIN, ans2 = INT_MIN;
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i = 2 ; i < n-1 ; i++) 
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        ans1 = dp[n-2];
        
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        
        for(int i = 3 ; i < n ; i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        
        ans2 = dp[n-1];
        
        return max(ans1,ans2);
    }
};