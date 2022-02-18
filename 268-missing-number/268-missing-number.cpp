class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1) / 2;
        int flag = 0,maxi = INT_MIN;
        int asum = 0;
        
        for(int i = 0 ; i < n ; i++) {
            asum += nums[i];
            if(nums[i] == 0)
                flag = 1;
            maxi = max(maxi,nums[i]);
        }
        
        if(sum - asum == 0 && flag == 1)
            return maxi + 1;
        return sum - asum;
    }
};