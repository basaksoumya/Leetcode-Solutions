class Solution {
public:
    
    
    int maxCoinsRecursive(vector<int> &nums,int i , int j, vector<vector<int>> &dp) {
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int maximum = INT_MIN;
        
        for(int k = i ; k <= j ; k++) {
            int temp = maxCoinsRecursive(nums,i,k-1,dp) + maxCoinsRecursive(nums,k+1,j,dp) + nums[i-1]*nums[k]*nums[j+1];
            maximum = max(maximum,temp);
        }
        return dp[i][j] = maximum;
    }
    
    
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return maxCoinsRecursive(nums,1,nums.size()-2,dp);
    }
};