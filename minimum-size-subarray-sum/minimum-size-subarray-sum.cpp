class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0;
        int ans = INT_MAX, l = 0, r = 0;
        
        while(r <= n) {
            if(sum >= target) {
                ans = min(ans,r-l);
                sum -= nums[l++];
            }
            else{
                if(r >= n)
                    break;
                sum += nums[r];
                r++;
            }
        }
        
        if(ans == INT_MAX)
            return 0;
        
        
        return ans;
    }
};